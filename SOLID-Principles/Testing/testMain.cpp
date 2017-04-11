// Tanner Kvarfordt
// A02052217

//
// Created by Tanner on 4/10/2017.
//

#include <iostream>
#include "ConfigurationTester.h"

int main() {
    ConfigurationTester configurationTester;
    configurationTester.testAddParameter(std::cout);
    configurationTester.testGetters(std::cout);
    configurationTester.testRemoveParameter(std::cout);
}