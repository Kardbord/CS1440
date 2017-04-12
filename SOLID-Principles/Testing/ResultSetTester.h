//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_RESULTSETTESTER_H
#define SOLID_PRINCIPLES_RESULTSETTESTER_H

#include <iostream>
#include <ostream>
#include "../ResultSet.h"

class ResultSetTester {
public:
    ResultSetTester() {}

    void testConstructorInheritance(std::ostream &out) const;

    void testPrint(std::ostream &out) const;
};


#endif //SOLID_PRINCIPLES_RESULTSETTESTER_H
