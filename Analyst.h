//
// Created by Tanner on 1/21/2017.
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include <string>
#include <vector>
#include "PurchaseSaleRecord.h"
#include "History.h"

//TODO add documentation

class Analyst {
public:
    Analyst() {}

    Analyst(std::ifstream &fin) { load(fin); }

    void load(std::ifstream &fin);

    std::string getName() const { return _name; }

    std::string getInitials() const { return _initials; }

    std::vector<History> getSimulations() const { return _simulations; }

private:
    std::string _name;
    std::string _initials;
    std::vector<History> _simulations;
};


#endif //ANALYSTCOMPARER_ANALYST_H
