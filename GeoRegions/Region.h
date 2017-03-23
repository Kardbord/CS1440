//
// Created by Stephen Clyde on 3/4/17.
//

#ifndef GEO_REGIONS_REGION_H
#define GEO_REGIONS_REGION_H

#include <string>
#include <vector>

class Region {
public:
    typedef enum RegionType {
        UnknownRegionType, WorldType, NationType, StateType, CountyType, CityType
    } x;

protected:
    unsigned int m_id = 0;
    RegionType m_regionType = UnknownRegionType;
    std::string m_name;
    unsigned long long int m_population = 0;
    double m_area = 0;
    bool m_isValid = false;

    /**
     * m_superIndex is the Region's index in its parent's m_subRegions vector
     * m_superIndex == nullptr if it is the root of all other regions
     */
    int *m_superIndex = nullptr;

    std::vector<Region *> m_subRegions;

private:
    static unsigned int m_nextId;
    int subRegionsAlloc = 10;

public:
    static Region *create(std::istream &in);

    static Region *create(const std::string &data);

    static Region *create(RegionType regionType, const std::string &data);

    static std::string regionLabel(RegionType regionType);

protected:
    Region();

    Region(RegionType type, const std::string data[]);

public:
    ~Region();

    unsigned int getId() const { return m_id; }

    RegionType getType() const { return m_regionType; }

    std::string getRegionLabel() const;

    const std::string &getName() const { return m_name; }

    void setName(const std::string &name) { m_name = name; }

    unsigned long long int getPopulation() const { return m_population; }

    void setPopulation(unsigned long long int population) { m_population = population; }

    double getArea() const { return m_area; }

    void setArea(double area) { m_area = area; }

    bool getIsValid() const { return m_isValid; }

    /**
     * @param id is the id (index in m_subRegions) of the subRegion to be removed
     * @return true if a region was found and removed, false otherwise
     */
    bool removeSubRegion(unsigned int const &id);

    /**
     * Removes all sub-Regions of the Region
     */
    void removeAllSubRegions();

    /**
     * @return the count of immediate subregions of the current region - ex: if current region is a world, return count of nations
     */
    unsigned long long int getImmediateSubRegionCount() { return m_subRegions.size(); }

    /**
     * @return the count of immediate subregions of the current region and those subregions' subregions
     */
    unsigned long long int getTotalSubRegionCount();

    Region *getSubRegion(unsigned int const &id) const;

    /**
     * @param region is the Region to potentially be appended to the Region::m_subRegions vector
     * @return true if region is sucessfully added, false if it is not
     */
    bool addSubRegion(Region *region);

    unsigned long long int computeTotalPopulation();

    void list(std::ostream &out);

    void displayAll(std::ostream &out, unsigned int displayLevel);

    void displaySubLevel(std::ostream &out, unsigned int displayLevel, bool showChildren);

    void save(std::ostream &out);

protected:
    virtual void validate();

    void loadChildren(std::istream &in);

    static unsigned int getNextId();

    Region *binaryFindSubRegion(int const start, int const end, int const target) const;
};


#endif //GEO_REGIONS_REGION_H
