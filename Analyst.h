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

    double profitLossPerDay();

    std::string getName() { return _name; }

    std::string getInitials() { return _initials; }

    int getSimulatedDays() { return _simDays; }

    int getNumRecords() { return _numRecords; }

private:
    std::string _name;
    std::string _initials;
    int _simDays;
    int _seedMoney;
    int _numRecords;
    std::vector<PurchaseSaleRecord> _history;
};


#endif //ANALYSTCOMPARER_ANALYST_H
