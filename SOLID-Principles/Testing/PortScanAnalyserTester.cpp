//
// Created by Tanner on 4/10/2017.
//

#include <fstream>
#include "PortScanAnalyserTester.h"
#include "../PortScanAnalyzer.h"

void PortScanAnalyserTester::testConstructorAndGetters(std::ostream &out) {
    out << "PortScanAnalyserTester::testConstructorAndGetters" << std::endl;

    try {
        PortScanAnalyzer analyser("40", "50");
        out << "Failure in PortScanAnalyzer constructor, failed to verify inputs" << std::endl;
    } catch (std::logic_error e) {
        // do nothing, this is expected behavior
    }

    try {
        PortScanAnalyzer analyzer("40", "30");

        Configuration analyzerConfig = analyzer.getConfiguration();

        if (analyzerConfig.getParamAsString("Likely Attack Port Threshold") != "40") {
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

void PortScanAnalyserTester::testRun(std::ostream &out) {
    out << "PortScanAnalyserTester::testRun" << std::endl;

    {
        const int NUM_LIKELY = 1;
        const int NUM_POSS = 0;

        std::ifstream fin("Testing/testData1.txt");

        if (!fin) {
            out << "Failed to open input file!" << std::endl;
            return;
        }

        PortScanAnalyzer analyzer1("2", "1");
        ResultSet results = analyzer1.run(fin);

        if (results.at("Likely Attackers").size() != NUM_LIKELY) {
            out << "Failure! analyzer1 did not detect all likely attackers" << std::endl;
            return;
        }

        if (results.at("Possible Attackers").size() != NUM_POSS) {
            out << "Failure! analyzer1 did not detect all possible attackers" << std::endl;
            return;
        }
    }
}
