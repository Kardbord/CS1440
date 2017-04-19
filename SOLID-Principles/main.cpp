#include <iostream>
#include "PortScanAnalyzer.h"
#include "DenialOfServiceAnalyzer.h"
#include <fstream>
#include <cassert>

void getThresholdInput(std::string &likelyThreshold, std::string &possibleThreshold, std::string const &analyzerType);

bool isValidThreshold(std::string const &threshold);

bool putResultsToScreen();

void runPortScanAnalyzer(bool toScreen);

void runDOSAnalyzer(bool toScreen);

// TODO: write UML
int main() {
    std::cout << "Welcome to the Hacker Attack Analyzer." << std::endl << std::endl;

    bool done = false;
    while (!done) {
        char input;
        std::cout << "Which analyzer would you like to use?" << std::endl
                  << "(P)ort Scan Analyzer" << std::endl
                  << "(D)OS Analyzer" << std::endl
                  << "(E)xit" << std::endl
                  << "Enter the letter of your selection: ";
        std::cin >> input;
        bool willPrintToScreen = false;
        if (input != 'E' && input != 'e') {
            willPrintToScreen = putResultsToScreen();
        }
        switch (input) {
            case 'P':
            case 'p':
                runPortScanAnalyzer(willPrintToScreen);
                break;
            case 'D':
            case 'd':
                runDOSAnalyzer(willPrintToScreen);
                break;
            case 'E':
            case 'e':
                done = true;
                break;
            default:
                break;
        }
    }
}

void runDOSAnalyzer(bool toScreen) {
    std::string likelyThreshold = "";
    std::string possibleThreshold = "";
    std::string timeframe = "";

    std::cout << "Please enter a timeframe for the DOS Analyzer: ";
    std::cin >> timeframe;

    while (!isValidThreshold(timeframe)) {
        std::cout << "Please enter a valid timeframe for the DOS Analyzer: ";
        std::cin >> timeframe;
    }

    getThresholdInput(likelyThreshold, possibleThreshold, "DOS Analyzer");

    DenialOfServiceAnalyzer denialOfServiceAnalyzer(timeframe, likelyThreshold, possibleThreshold);

    std::ifstream fin("./SampleData.csv");
    if (!fin) {
        std::cout << "Could not open input file. Shutting down..." << std::endl;
        std::exit(1);
    }

    if (toScreen) {
        denialOfServiceAnalyzer.run(fin).print(std::cout);
    } else {
        std::ofstream fout("DOS_Scan_Results.txt");
        assert(fout);
        denialOfServiceAnalyzer.run(fin).print(fout);
        fout.close();
    }
    fin.close();
}

void runPortScanAnalyzer(bool toScreen) {
    std::string likelyThreshold = "";
    std::string possibleThreshold = "";

    getThresholdInput(likelyThreshold, possibleThreshold, "Port Scan Analyzer");

    PortScanAnalyzer portScanAnalyzer(likelyThreshold, possibleThreshold);

    std::ifstream fin("./SampleData.csv");
    if (!fin) {
        std::cout << "Could not open input file. Shutting down..." << std::endl;
        std::exit(1);
    }

    if (toScreen) {
        portScanAnalyzer.run(fin).print(std::cout);
    } else {
        std::ofstream fout("PortScanResults.txt");
        assert(fout);
        portScanAnalyzer.run(fin).print(fout);
        fout.close();
    }

    fin.close();
}

void getThresholdInput(std::string &likelyThreshold, std::string &possibleThreshold, std::string const &analyzerType) {

    std::cout << "Enter a value for likelyThreshold for the " << analyzerType << ": ";
    std::cin >> likelyThreshold;
    while (!isValidThreshold(likelyThreshold)) {
        std::cout << "Enter a valid value for likelyThreshold for the " << analyzerType << ": ";
        std::cin >> likelyThreshold;
    }

    std::cout << "Enter a value for possibleThreshold for the " << analyzerType << " (must be less than "
              << likelyThreshold << "): ";
    std::cin >> possibleThreshold;
    while (!isValidThreshold(possibleThreshold)) {
        std::cout << "Enter a valid value for possibleThreshold for the " << analyzerType << " (must be less than "
                  << likelyThreshold << "): ";
        std::cin >> possibleThreshold;
    }

}

bool isValidThreshold(std::string const &threshold) {
    try {
        if (std::stoi(threshold) < 0) return false;
    } catch (std::exception) {
        return false;
    }
    return true;
}

bool putResultsToScreen() {
    char input = 'a';
    while (input != 'R' && input != 'r' && input != 'C' && input != 'c') {
        std::cout << "Output the results to: " << std::endl
                  << "(R)esults text file" << std::endl
                  << "(C)onsole" << std::endl
                  << "Enter the letter of your selection: ";
        std::cin >> input;
    }

    switch (input) {
        case 'R':
        case 'r':
            return false;
        case 'C':
        case 'c':
            return true;
        default:
            break;
    }

    return true; // deal with compiler warning even though this is never reached
}