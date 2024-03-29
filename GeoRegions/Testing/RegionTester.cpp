//
// Created by Stephen Clyde on 3/13/17.
//

#include "RegionTester.h"

#include "../Region.h"

#include <iostream>
#include <fstream>

void RegionTester::testCreateFromStream() {
    std::cout << "RegionTester::testCreateFromStream" << std::endl;

    // Load a file with just the world in it
    {
        std::string inputFile = "SampleData/sampleData-1.txt";
        std::ifstream inputStream(inputFile);
        Region *region = Region::create(inputStream);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::WorldType) {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << region->getRegionLabel() << std::endl;
            return;
        }
    }

    // Load a file with the and four nations
    {
        std::string inputFile = "SampleData/sampleData-2.txt";
        std::ifstream inputStream(inputFile);
        Region *world = Region::create(inputStream);
        if (world == nullptr) {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->getType() != Region::RegionType::WorldType) {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << world->getRegionLabel() << std::endl;
            return;
        }

        if (world->getImmediateSubRegionCount() != 4) {
            std::cout << "Failed to load the four expected nations from " << inputFile << std::endl;
            std::cout << "\tExpected 4 nations, but loaded a " << world->getImmediateSubRegionCount() << std::endl;
            return;
        }

        // Note that this only works because the input file is made up entirely of nations and the world has id 1
        for (unsigned int nationIndex = 2; nationIndex < world->getImmediateSubRegionCount(); nationIndex++) {
            Region *nation = world->getSubRegion(nationIndex);
            if (nation->getType() != Region::RegionType::NationType) {
                std::cout << "Failed to create correct type of sub-region in the world from " << inputFile << std::endl;
                std::cout << "\tExpected nation sub-region type, but created a " << nation->getRegionLabel()
                          << std::endl;
                return;
            }
        }
    }

}

void RegionTester::testCreateFromString() {
    std::cout << "RegionTester::testCreateFromString" << std::endl;

    {
        std::string inputString = "2,Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Country region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny Country\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "3,Tiny State,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "4,Tiny County,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "5,Tiny City,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString
                      << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString
                      << std::endl;
            return;
        }
    }

}

void RegionTester::testCreateFromTypeAndString() {
    std::cout << "RegionTester::testCreateFromTypeAndString" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny State,30,20";
        Region *region = Region::create(Region::RegionType::StateType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny County,30,20";
        Region *region = Region::create(Region::RegionType::CountyType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny City,30,20";
        Region *region = Region::create(Region::RegionType::CityType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30";
        Region *r1 = Region::create(Region::NationType, inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString
                      << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2";
        Region *r1 = Region::create(Region::NationType, inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString
                      << std::endl;
            return;
        }
    }

}

void RegionTester::testGettersAndSetters() {
    std::cout << "RegionTester::testGettersAndSetters" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }

        region->setName("Really Tiny County");
        if (region->getName() != "Really Tiny County") {
            std::cout << "Failed to set the name for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Really Tiny County\", but got \"" << region->getName() << "\"" << std::endl;
            return;
        }

        region->setPopulation(5);
        if (region->getPopulation() != 5) {
            std::cout << "Failed to set the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 5, but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        region->setArea(2);
        if (region->getArea() != 2) {
            std::cout << "Failed to set the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 2, but got \"" << region->getArea() << "\"" << std::endl;
            return;
        }
    }
}

void RegionTester::testSubRegions() {
    std::cout << "RegionTester::testSubRegions" << std::endl;

    // sampleData-2

    std::string inputFile = "SampleData/sampleData-2.txt";
    std::ifstream inputStream(inputFile);
    Region *world = Region::create(inputStream);
    if (world == nullptr) {
        std::cout << "testSubRegions failed to create a region from " << inputFile << std::endl;
        return;
    }

    // Test the 2 getSubRegionCount methods
    if (world->getImmediateSubRegionCount() != 4) {
        std::cout << "Failure in world->getImmediateSubRegionCount with " << inputFile << std::endl;
        return;
    }

    if (world->getTotalSubRegionCount() != 4) {
        std::cout << "Failure in world->getImmediateSubRegionCount with " << inputFile << std::endl;
        return;
    }

    auto nation = world->getSubRegion(18); // 18 due to Region::m_nextId being a static variable

    if (nation == nullptr) {
        std::cout << "testSubRegions failed to create a nation from world->getSubRegion(18)" << std::endl;
        return;
    }

    if (nation->getImmediateSubRegionCount() != 0) {
        std::cout << "Failure in nation->getImmediateSubRegionCount with " << inputFile << ", result should be 0"
                  << std::endl;
        return;
    }

    if (nation->getTotalSubRegionCount() != 0) {
        std::cout << "Failure in nation->getImmediateSubRegionCount with " << inputFile << ", result should be 0"
                  << std::endl;
        return;
    }

    // Test addSubRegion
    std::string inputString = "2,Tiny Country,30,20";
    Region *newNation = Region::create(inputString);
    if (!world->addSubRegion(newNation)) {
        std::cout << "Failure in world->addRegion(newNation) with" << inputFile << std::endl;
        return;
    }

    if (world->getImmediateSubRegionCount() != 5) {
        std::cout << "Failure in world->getImmediateSubRegionCount after adding newNation with " << inputFile
                  << std::endl;
        return;
    }

    if (world->getTotalSubRegionCount() != 5) {
        std::cout << "Failure in world->getImmediateSubRegionCount after adding newNation with " << inputFile
                  << std::endl;
        return;
    }

    std::string inputString2 = "3,Tiny State,30,20";
    Region *newState = Region::create(inputString2);
    if (!nation->addSubRegion(newState)) {
        std::cout << "Failure in nation->addRegion(newState) with " << inputFile << std::endl;
        return;
    }

    if (world->getImmediateSubRegionCount() != 5) {
        std::cout << "Failure in world->getImmediateSubRegionCount after adding newState with " << inputFile
                  << ", result should be 5" << std::endl;
        return;
    }

    if (world->getTotalSubRegionCount() != 6) {
        std::cout << "Failure in world->getImmediateSubRegionCount after adding newState with " << inputFile
                  << ", result should be 6" << std::endl;
        return;
    }

    if (nation->getImmediateSubRegionCount() != 1) {
        std::cout << "Failure in nation->getImmediateSubRegionCount with " << inputFile << ", result should be 1"
                  << std::endl;
        return;
    }

    if (nation->getTotalSubRegionCount() != 1) {
        std::cout << "Failure in nation->getImmediateSubRegionCount with " << inputFile << ", result should be 1"
                  << std::endl;
        return;
    }

    if (!world->removeSubRegion(19)) {
        std::cout << "Failure in world->removeSubRegion(19) with " << inputFile << std::endl;
        return;
    }

    if (world->getImmediateSubRegionCount() != 4) {
        std::cout << "Failure in world->getImmediateSubRegionCount after world->removeSubRegion(19) " << inputFile
                  << ", result should be 4" << std::endl;
        return;
    }

    if (world->getTotalSubRegionCount() != 5) {
        std::cout << "Failure in world->getImmediateSubRegionCount after world->removeSubRegion(19) " << inputFile
                  << ", result should be 5" << std::endl;
        return;
    }

    if (!world->removeSubRegion(18)) {
        std::cout << "Failure in world->removeSubRegion(18) with " << inputFile << std::endl;
        return;
    }

    if (world->getImmediateSubRegionCount() != 3) {
        std::cout << "Failure in world->getImmediateSubRegionCount after world->removeSubRegion(19) " << inputFile
                  << ", result should be 4" << std::endl;
        return;
    }

    if (world->getTotalSubRegionCount() != 3) {
        std::cout << "Failure in world->getImmediateSubRegionCount after world->removeSubRegion(19) " << inputFile
                  << ", result should be 5" << std::endl;
        return;
    }
}

void RegionTester::testComputeTotalPopulation() {
    std::cout << "RegionTester::testComputeTotalPopulation" << std::endl;

    // just defining a scope, don't mind me. sampleData-1
    {
        std::string inputFile = "SampleData/sampleData-1.txt";
        std::ifstream inputStream(inputFile);
        Region *region = Region::create(inputStream);
        if (region == nullptr) {
            std::cout << "testComputeTotalPopulation failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (region->computeTotalPopulation() != (unsigned long long) 7324782225) {
            std::cout << "Failure in testComputeTotalPopulation with " << inputFile << std::endl;
            return;
        }

    }

    // another scope for sampleData-2
    {
        std::string inputFile = "SampleData/sampleData-2.txt";
        std::ifstream inputStream(inputFile);
        Region *world = Region::create(inputStream);
        if (world == nullptr) {
            std::cout << "testComputeTotalPopulation failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->computeTotalPopulation() !=
            (unsigned long long) (7324782225 + 324118787 + 82175700 + 54786300 + 23519518)) {
            std::cout << "Failure in testComputeTotalPopulation with " << inputFile << std::endl;
            return;
        }
    }

    // another scope for sampleData-3
    {
        std::string inputFile = "SampleData/sampleData-3.txt";
        std::ifstream inputStream(inputFile);
        Region *world = Region::create(inputStream);
        if (world == nullptr) {
            std::cout << "testComputeTotalPopulation failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->computeTotalPopulation() != (unsigned long long) (7856306962)) {
            std::cout << "Failure in testComputeTotalPopulation with " << inputFile << std::endl;
            return;
        }
    }

    // another scope for sampleData-4
    {
        std::string inputFile = "SampleData/sampleData-4.txt";
        std::ifstream inputStream(inputFile);
        Region *world = Region::create(inputStream);
        if (world == nullptr) {
            std::cout << "testComputeTotalPopulation failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->computeTotalPopulation() !=
            (unsigned long long) (0 + 64363 + 425 + 116909 + 48913 + 9659 + 22620 + 263640 + 3252 + 62 + 2352 +
                                  3523523 + 3525)) {
            std::cout << "Failure in testComputeTotalPopulation with " << inputFile << std::endl;
            return;
        }
    }
}
