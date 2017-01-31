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

    // Initializes data members based on the input file provided in the cmd arguments
    History(std::ifstream &fin) { load(fin); }

    // Initializes data members based on the input file provided in the cmd arguments
    void load(std::ifstream &fin);

    // Computes, in pennies, the total profit/loss for all PurchasesSales in the History
    double computeTotalProfitLoss();

    // Computes, in pennies, the total profit/loss per day for all PurchasesSales in the History
    double computeProfitLossPerDay();

    // Computes, in pennies, the total profit/loss per day for a given company's stock
    double computeStockPerformance(std::string const &symbol);

    int getSimDays() const { return _simDays; }

    int getSeedMoney() const { return _seedMoney; }

    int getNumRecords() const { return _numRecords; }

    std::vector<PurchaseSaleRecord> getRecords() const { return _records; }

private:
    int _simDays;
    int _seedMoney;
    int _numRecords;
    std::vector<PurchaseSaleRecord> _records;
};


#endif //ANALYSTCOMPARER_HISTORY_H
