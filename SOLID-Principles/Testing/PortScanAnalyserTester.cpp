//
// Created by Tanner on 4/10/2017.
//

#include "PortScanAnalyserTester.h"
#include "../PortScanAnalyzer.h"

void PortScanAnalyserTester::testConstructorAndGetters(std::ostream &out) {
    out << "PortScanAnalyserTester::testConstructorAndGetters" << std::endl;

    PortScanAnalyser analyzer("20", "30");

    Configuration analyzerConfig = analyzer.getConfiguration();

    try {
        if (analyzerConfig.getParamAsString("Likely Attack Port Threshold") != "20") {
            out << "Failure in constructor, values are not as assigned" << std::endl;
            return;
        }

        if (analyzerConfig.getParamAsString("Possible Attack Port Threshold") != "30") {
            out << "Failure in constructor, values are not as assigned" << std::endl;
            return;
        }

        try {
            analyzerConfig.getParamAsString("not a real parameter");
            out << "Failure in constructor, configParam exists that should not" << std::endl;
            return;
        } catch (std::exception e) {
            // Do nothing, this is expected behavior
        }

    } catch (std::exception e) {
        out << "Failure in testConstructorAndGetters, threw unexpected exception" << std::endl;
    }

}
