//
// Created by Tanner on 4/10/2017.
//

#include <fstream>
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

void DenialOfServiceAnalyzerTester::testRun(std::ostream &out) {
    out << "DenialOfServiceAnalyzerTester::testRun" << std::endl;

    // Analyzer 1
    {
        const int NUM_LIKELY = 1;
        const int NUM_POSS = 0;

        std::ifstream fin("Testing/testData2.txt");

        if (!fin) {
            out << "Failed to open input file!" << std::endl;
            return;
        }

        DenialOfServiceAnalyzer analyzer1("5", "3", "2");
        ResultSet results = analyzer1.run(fin);

        try {
            if (results.at("Likely Attackers").size() != NUM_LIKELY) {
                out << "Failure! analyzer1 did not detect all likely attackers" << std::endl;
                return;
            }

            if (results.at("Possible Attackers").size() != NUM_POSS) {
                out << "Failure! analyzer1 did not detect all possible attackers" << std::endl;
                return;
            }
        } catch (std::exception) {
            out << "Failure while testing analyzer1, threw unexpected exception" << std::endl;
        }
    }

    // Analyzer 2
    {
        const int NUM_LIKELY = 1;
        const int NUM_POSS = 0;

        std::ifstream fin("Testing/testData2.txt");

        if (!fin) {
            out << "Failed to open input file!" << std::endl;
            return;
        }

        DenialOfServiceAnalyzer analyzer2("10", "3", "2");
        ResultSet results = analyzer2.run(fin);

        try {
            if (results.at("Likely Attackers").size() != NUM_LIKELY) {
                out << "Failure! analyzer2 did not detect all likely attackers" << std::endl;
                return;
            }

            if (results.at("Possible Attackers").size() != NUM_POSS) {
                out << "Failure! analyzer2 did not detect all possible attackers" << std::endl;
                return;
            }
        } catch (std::exception) {
            out << "Failure while testing analyzer2, threw unexpected exception" << std::endl;
        }
    }
}
