//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>
#include <cmath>
#include <typeinfo>
#include <iostream>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;

Region *Region::create(std::istream &in) {
    Region *region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line != "") {
        region = create(line);
        if (region != nullptr)
            region->loadChildren(in);
    }
    return region;
}

Region *Region::create(const std::string &data) {
    Region *region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos) {
        std::string regionTypeStr = data.substr(0, commaPos);
        regionData = data.substr(commaPos + 1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid) {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region *Region::create(RegionType regionType, const std::string &data) {
    Region *region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
            default:
                break;
        }

        // If the region isn't valid, git ride of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType) {
    std::string label = "Unknown";
    switch (regionType) {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() {}

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true) {
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
}

Region::~Region() {
    // TODO: verify this is correct...
    for (auto &&r : m_subRegions) {
        if (r != nullptr) {
            delete r; // call the destructor to delete any subRegions of the subRegion
            r = nullptr;
        }
    }
    m_subRegions.clear();
}

std::string Region::getRegionLabel() const {
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation() {
    // TODO: test me
    unsigned int population = m_population;
    for (auto &&r : m_subRegions) {
        if (r != nullptr) {
            population += r->getPopulation();
        }
    }
    return population;
}

void Region::list(std::ostream &out) {
    out << std::endl;
    out << getName() << ":" << std::endl;

    for (auto &&r : m_subRegions) {
        out << r->getId() << " " << r->getName() << std::endl;
    }
}

void Region::displayAll(std::ostream &out, unsigned int displayLevel) {
    if (displayLevel > 0) {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    for (auto &&r : m_subRegions) {
        if (r != nullptr) r->displayAll(out, displayLevel + 1);
    }

}

void Region::displaySubLevel(std::ostream &out, unsigned int displayLevel, bool showChildren) {
    if (displayLevel > 0) {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChildren) {
        for (auto &&r : m_subRegions) {
            if (r != nullptr) r->displaySubLevel(out, displayLevel + 1, false);
        }
    }
}

void Region::save(std::ostream &out) {
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    // TODO: test this
    for (auto &&r : m_subRegions) {
        if (r != nullptr) r->save(out);
    }

    out << regionDelimiter << std::endl;
}

void Region::validate() {
    m_isValid = (m_area != UnknownRegionType && m_name != "" && m_area >= 0);
}

void Region::loadChildren(std::istream &in) {
    std::string line;
    bool done = false;
    while (!in.eof() && !done) {
        std::getline(in, line);
        if (line == regionDelimiter) {
            done = true;
        } else {
            Region *child = create(line);
            if (child != nullptr) {
                if (!addSubRegion(child)) {
                    std::cerr << "Input file passed to Region::loadChildren is improperly formatted.\n"
                              << child->getName() << "not added to subRegions\n";
                }
                child->loadChildren(in);
            }
        }
    }
}

unsigned int Region::getNextId() {
    if (m_nextId == UINT32_MAX)
        m_nextId = 1;

    return m_nextId++;
}

Region *Region::findSubRegion(unsigned int const &id) const {
    if (id < 0 || id >= m_nextId) return nullptr;

    int mid = (int) std::floor(m_subRegions.size() / 2);

    if (m_subRegions[mid] != nullptr) {
        if (m_subRegions[mid]->getId() == id) return m_subRegions[mid];

        if (m_subRegions[mid]->getId() > id) {
            return binaryFindSubRegion(0, mid - 1, id);
        } else {
            return binaryFindSubRegion(mid + 1, (int) m_subRegions.size() - 1, id);
        }
    } else return nullptr;
}

// TODO: test me
bool Region::removeSubRegion(unsigned int const &id) {
    if (id < 0 || id > m_subRegions.size()) return false;

    Region *delRegion = findSubRegion(id);

    if (delRegion == nullptr) return false;

    delete delRegion;

    if (delRegion->m_superIndex != nullptr) {
        m_subRegions.erase(m_subRegions.begin() + *delRegion->m_superIndex);
    }
    return true;
}

void Region::removeSubRegions() {
    for (int i = 0; i < m_subRegions.size(); ++i) {
        removeSubRegion((const unsigned int &) i);
    }
}

bool Region::addSubRegion(Region *region) {
    if (region == nullptr) return false;

    switch (this->getType()) {
        case WorldType:
            if (region->getType() == NationType) {
                m_subRegions.push_back(region);
                m_subRegions.back()->m_superIndex = new int((int) (m_subRegions.size() - 1));
                return true;
            }
            return false;
        case NationType:
            if (region->getType() == StateType) {
                m_subRegions.push_back(region);
                m_subRegions.back()->m_superIndex = new int((int) (m_subRegions.size() - 1));
                return true;
            }
            return false;
        case StateType:
            if (region->getType() == CountyType || region->getType() == CityType) {
                m_subRegions.push_back(region);
                m_subRegions.back()->m_superIndex = new int((int) (m_subRegions.size() - 1));
                return true;
            }
            return false;
        case CountyType:
            if (region->getType() == CityType) {
                m_subRegions.push_back(region);
                m_subRegions.back()->m_superIndex = new int((int) (m_subRegions.size() - 1));
                return true;
            }
            return false;
        case CityType:
            return false;
        default:
            return false;
    }
}


Region *Region::binaryFindSubRegion(int const start, int const end, int const target) const {
    if (start < 0 || start > end || end > m_subRegions.size()) return nullptr;

    int mid = (start + end) / 2;

    if (mid >= m_subRegions.size() || mid < 0) return nullptr;

    if (m_subRegions[mid] != nullptr) {

        if (m_subRegions[mid]->getId() == target) return m_subRegions[mid];

        if (m_subRegions[mid]->getId() > target) {
            return binaryFindSubRegion(start, mid - 1, target);
        } else {
            return binaryFindSubRegion(mid + 1, end, target);
        }

    } else return nullptr;

}
