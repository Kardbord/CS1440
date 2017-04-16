//
// Created by Tanner on 4/10/2017.
//

#include "DenialOfServiceAnalyzerTester.h"

void DenialOfServiceAnalyzerTester::testConstructorAndGetters(std::ostream &out) {
    out << "DenialOfServiceAnalyzerTester::testConstructorAndGetters" << std::endl;

    try {
        DenialOfServiceAnalyzer analyzer("100", "20", "30");
        out << "Failure in DOSAnalyzer constructor, failed to verify inputs" << std::endl;
    } catch (std::logic_error e) {
        // do nothing, this is expected behavior
    }

    try {
        DenialOfServiceAnalyzer analyzer("100", "30", "20");

        Configuration analyzerConfig = analyzer.getConfiguration();

        if (analyzerConfig.getParamAsString("Timeframe") != "100") {
            out << "Failure in constructor, values are not as assigned" << std::endl;
            return;
        }

        if (analyzerConfig.getParamAsString("Likely Attack Message Threshold") != "30") {
            out << "Failure in constructor, values are not as assigned" << std::endl;
            return;
        }

        if (analyzerConfig.getParamAsString("Possible Attack Message Threshold") != "20") {
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
