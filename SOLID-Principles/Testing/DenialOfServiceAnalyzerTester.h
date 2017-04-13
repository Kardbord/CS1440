//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_DENAILOFSERVICEANALYZERTESTER_H
#define SOLID_PRINCIPLES_DENAILOFSERVICEANALYZERTESTER_H

#include <ostream>
#include <stdexcept>
#include "../DenialOfServiceAnalyzer.h"

class DenialOfServiceAnalyzerTester {
public:
    DenialOfServiceAnalyzerTester() {}

    void testConstructorAndGetters(std::ostream &out);
};


#endif //SOLID_PRINCIPLES_DENAILOFSERVICEANALYZERTESTER_H
