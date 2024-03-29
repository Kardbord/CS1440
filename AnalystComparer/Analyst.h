//
// Created by Tanner Kvarfordt on 1/21/2017.
// A02052217
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include <string>
#include <vector>
#include "PurchaseSaleRecord.h"
#include "History.h"

class Analyst {
public:
    Analyst() {}

    // Initializes data members based on the input file provided in the cmd arguments
    Analyst(std::ifstream &fin) { load(fin); }

    // Initializes data members based on the input file provided in the cmd arguments
    void load(std::ifstream &fin);

    std::string getName() const { return _name; }

    std::string getInitials() const { return _initials; }

    History getHistory() const { return _history; }

private:
    std::string _name;
    std::string _initials;
    History _history;
};


#endif //ANALYSTCOMPARER_ANALYST_H
