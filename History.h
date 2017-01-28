//
// Created by Tanner on 1/28/2017.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H


#include <vector>
#include "PurchaseSaleRecord.h"

class History {
public:
    int getSimDays() { return _simDays; }

    int getSeedMoney() { return _seedMoney; }

    int getNumRecords() { return static_cast<int>(_records.size()); }

private:
    int _simDays;
    int _seedMoney;
    int _numRecords;
    std::vector<PurchaseSaleRecord> _records;
};


#endif //ANALYSTCOMPARER_HISTORY_H
