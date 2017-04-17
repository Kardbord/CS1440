// Tanner Kvarfordt
// A02052217

//
// Created by Tanner on 4/10/2017.
//

#include <iostream>
#include "ConfigurationTester.h"
#include "ResultSetTester.h"
#include "DenialOfServiceAnalyzerTester.h"
#include "PortScanAnalyserTester.h"

int main() {
    ConfigurationTester configurationTester;
    configurationTester.testGetters(std::cout);
    configurationTester.testAddPair(std::cout);

    ResultSetTester resultSetTester;
    resultSetTester.testConstructorInheritance(std::cout);
    resultSetTester.testPrint(std::cout);

    DenialOfServiceAnalyzerTester denialOfServiceAnalyzerTester;
    denialOfServiceAnalyzerTester.testConstructorAndGetters(std::cout);
    
    PortScanAnalyserTester portScanAnalyzerTester;
    portScanAnalyzerTester.testConstructorAndGetters(std::cout);
    portScanAnalyzerTester.testRun(std::cout);
    
    return EXIT_SUCCESS;
}