#include <iostream>
#include "PortScanAnalyzer.h"
#include <fstream>

int main() {

    {
        PortScanAnalyzer portScanAnalyzer("50", "2");

        std::ifstream fin("./SampleData.csv");
        if (!fin) {
            std::cout << "Could not open input file. Shutting down..." << std::endl;
        }

        portScanAnalyzer.run(fin).print(std::cout);
        fin.close();
    }
}