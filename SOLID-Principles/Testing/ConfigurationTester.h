//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_CONFIGURATIONTESTER_H
#define SOLID_PRINCIPLES_CONFIGURATIONTESTER_H


#include <ostream>

class ConfigurationTester {
public:
    ConfigurationTester() {}

    void testAddParameter(std::ostream &out);

    void testGetters(std::ostream &out);

    void testRemoveParameter(std::ostream &out);
};


#endif //SOLID_PRINCIPLES_CONFIGURATIONTESTER_H
