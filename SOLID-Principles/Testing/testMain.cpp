// Tanner Kvarfordt
// A02052217

//
// Created by Tanner on 4/10/2017.
//

#include <iostream>
#include "ConfigurationTester.h"
#include "ResultSetTester.h"
#include "DenialOfServiceAnalyzerTester.h"

int main() {
    ConfigurationTester configurationTester;
    configurationTester.testGetters(std::cout);
    configurationTester.testAddPair(std::cout);

    std::cout << std::endl;

    ResultSetTester resultSetTester;
    resultSetTester.testConstructorInheritance(std::cout);
    resultSetTester.testPrint(std::cout);

    std::cout << std::endl;

    DenialOfServiceAnalyzerTester denialOfServiceAnalyzerTester;
    denialOfServiceAnalyzerTester.testConstructorAndGetters(std::cout);
}