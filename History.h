//
// Created by Tanner on 1/28/2017.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H


#include <vector>
#include "PurchaseSaleRecord.h"
#include <fstream>

class History {
public:

    History() {}

    History(std::ifstream &fin) { load(fin); }

    void load(std::ifstream &fin);

    int getSimDays() { return _simDays; }

    int getSeedMoney() { return _seedMoney; }

    int getNumRecords() { return _numRecords; }

private:
    int _simDays;
    int _seedMoney;
    int _numRecords;
    std::vector<PurchaseSaleRecord> _records;
};


#endif //ANALYSTCOMPARER_HISTORY_H
