//
// Created by Tanner on 1/28/2017.
// A02052217
//

#ifndef ANALYSTCOMPARER_COMPARER_H
#define ANALYSTCOMPARER_COMPARER_H


#include "Analyst.h"

class Comparer {
public:
    Comparer() {}

    // Initializes data members based on the input file provided in the cmd arguments
    Comparer(int argv, char *argc[]) { load(argv, argc); }

    // Creates Analysts and their histories, etc. from the command line arguments
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

    // Stores the stock symbol of every company that an Analyst invested in
    void loadSymbols();

    void outputInvestorNames(std::ofstream &outputStream) const;

    void outputOverallPerformance(std::ofstream &outputStream) const;

    void outputStockPerformance(std::ofstream &outputStream) const;


};


#endif //ANALYSTCOMPARER_COMPARER_H
