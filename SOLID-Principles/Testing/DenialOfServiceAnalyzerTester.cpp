//
// Created by Tanner on 4/10/2017.
//

#include "DenialOfServiceAnalyzerTester.h"

void DenialOfServiceAnalyzerTester::testConstructorAndGetters(std::ostream &out) {
    out << "DenialOfServiceAnalyzerTester::testConstructorAndGetters" << std::endl;

    DenialOfServiceAnalyzer analyzer("20", "30", "40");

    try {
        if (analyzer.getConfigPair("Timeframe").second != "20") {
            out << "Failure in constructor, Timeframe config parameter should be \"20\"" << std::endl;
            return;
        }

        if (analyzer.getConfigPair("Likely Attack Message Count").second != "30") {
            out << "Failure in constructor, Likely Attack Message Count config parameter should be \"30\"" << std::endl;
            return;
        }

        if (analyzer.getConfigPair("Possible Attack Message Count").second != "40") {
            out << "Failure in constructor, Possible Attack Message Count config parameter should be \"40\""
                << std::endl;
            return;
        }

        try {
            analyzer.getConfigPair("adsf");
            out << "Failure in getConfigPair(\"asdf\"), should have thrown exception" << std::endl;
        } catch (std::out_of_range e) {
            // do nothing, this is expected behavior
        }

        try {
            analyzer.getConfigPair("1");
            out << "Failure in getConfigPair(\"1\"), should have thrown exception" << std::endl;
        } catch (std::out_of_range e) {
            // do nothing, this is expected behavior
        }

    } catch (std::out_of_range e) {
        out << "Failure while testing getConfigPair, threw an unexpected exception" << std::endl;
    }
}
