//
// Created by Tanner Kvarfordt on 1/28/2017.
// A02052217
//

#include "History.h"

// Initializes data members based on the input file provided in the cmd arguments
void History::load(std::ifstream &fin) {

    fin >> _simDays;
    fin >> _seedMoney;
    fin >> _numRecords;

    for (int i = 0; i < _numRecords; ++i) {
        _records.push_back(PurchaseSaleRecord(fin));
    }
}

// Computes, in pennies, the total profit/loss for all PurchasesSales in the History
double History::computeTotalProfitLoss() {
    double tpl = 0;
    for (auto &&r : _records) {
        tpl += r.computeProfitLoss();
    }
    return tpl;
}

// Computes, in pennies, the total profit/loss per day for all PurchasesSales in the History
double History::computeProfitLossPerDay() {
    return computeTotalProfitLoss() / _simDays;
}

// Computes, in pennies, the total profit/loss per day for a given company's stock
double History::computeStockPerformance(std::string const &symbol) {

    if (_records.empty()) throw "Error! This _history has no records!";

    /* Find min purchase date and max sale date to calculate date range for stock,
     * and find total profit/loss for the stock*/
    double minPDate = -1;
    double maxSDate = -1;
    double TPL = 0;
    bool hadSymbol = false;
    for (auto &&r : _records) {
        if (r.getCompany() == symbol) {

            hadSymbol = true;

            TPL += r.computeProfitLoss();

            if (r.getPurchaseDate() < minPDate || minPDate < 0) {
                minPDate = r.getPurchaseDate();
            }
            if (r.getSaleDate() > maxSDate || maxSDate < 0) {
                maxSDate = r.getSaleDate();
            }
        }
    }

    if (!hadSymbol) return -1000000; // if the symbol was not in the _history

    double investmentDays = (maxSDate - minPDate) / (24 * 60); // 24 hours in a day, 60 minutes in an hour

    return TPL / investmentDays;
}
