//
// Created by Tanner on 1/21/2017.
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include <string>
#include <vector>
#include "PurchaseSaleRecord.h"

//TODO add documentation

class Analyst {
public:
    Analyst();

    double computeTotalProfitLoss();

    double computeProfitLossPerDay();

    std::string getName() { return _name; }

    std::string getInitials() { return _initials; }

private:
    std::string _name;
    std::string _initials;
};


#endif //ANALYSTCOMPARER_ANALYST_H
