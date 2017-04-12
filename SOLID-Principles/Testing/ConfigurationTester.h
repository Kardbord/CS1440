//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_CONFIGURATIONTESTER_H
#define SOLID_PRINCIPLES_CONFIGURATIONTESTER_H


#include <ostream>
#include "../Configuration.h"

class ConfigurationTester {
public:
    ConfigurationTester() {}

    void testAddParameter(std::ostream &out) const;

    void testGetters(std::ostream &out) const;

    void testRemoveParameter(std::ostream &out) const;

private:
    Configuration setUp(std::ostream &out) const;
};


#endif //SOLID_PRINCIPLES_CONFIGURATIONTESTER_H
