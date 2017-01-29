//
// Created by Tanner on 1/28/2017.
//

#ifndef ANALYSTCOMPARER_COMPARER_H
#define ANALYSTCOMPARER_COMPARER_H


#include "Analyst.h"

class Comparer {
public:
    Comparer() {}

    Comparer(int argv, char *argc[]) { load(argv, argc); }

    int load(int argv, char *argc[]);

    int compare() const;

    std::vector<Analyst> getAnalysts() const { return _analysts; }

    int getSymbolCount() { return _symbolCount; }

    std::vector<std::string> getSymbols() { return _symbols; }

private:

    // private data members

    std::vector<Analyst> _analysts;
    int _analystCount;
    int _symbolCount;
    std::string _outputFilename;
    std::vector<std::string> _symbols;

    // private member functions

    void loadSymbols();

    void outputInvestorNames(std::ofstream &outputStream) const;

    void outputOverallPerformance(std::ofstream &outputStream) const;

    void outputStockPerformance(std::ofstream &outputStream) const;
};


#endif //ANALYSTCOMPARER_COMPARER_H
