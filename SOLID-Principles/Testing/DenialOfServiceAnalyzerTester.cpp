//
// Created by Tanner on 4/10/2017.
//

#include "DenialOfServiceAnalyzerTester.h"

void DenialOfServiceAnalyzerTester::testConstructorAndGetters(std::ostream &out) {
    out << "DenialOfServiceAnalyzerTester::testConstructorAndGetters" << std::endl;

    DenialOfServiceAnalyzer analyzer("20", "30", "40");

    Configuration analyzerConfig = analyzer.getConfiguration();

    try {
        if (analyzerConfig.getParamAsString("Timeframe") != "20") {
            out << "Failure in constructor, values are not as assigned" << std::endl;
            return;
        }

        if (analyzerConfig.getParamAsString("Likely Attack Message Count") != "30") {
            out << "Failure in constructor, values are not as assigned" << std::endl;
            return;
        }

        if (analyzerConfig.getParamAsString("Possible Attack Message Count") != "40") {
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
