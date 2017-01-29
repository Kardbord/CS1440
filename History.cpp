//
// Created by Tanner on 1/28/2017.
//

#include "History.h"

void History::load(std::ifstream &fin) {

    fin >> _simDays;
    fin >> _seedMoney;
    fin >> _numRecords;

    for (int i = 0; i < _numRecords; ++i) {
        _records.push_back(PurchaseSaleRecord(fin));
    }
}

double History::computeTotalProfitLoss() {
    double tpl = 0;
    for (auto &&r : _records) {
        tpl += r.computeProfitLoss();
    }
    return tpl;
}

double History::computeProfitLossPerDay() {
    return computeTotalProfitLoss() / _simDays;
}

// Returns, in pennies per day, a stock's profit/loss per day
double History::computeStockPerformance(std::string const &symbol) {

    if (_records.empty()) throw "Error! This history has no records!";

    /* Find min purchase date and max sale date to calculate date range for stock,
     * and find total profit/loss for the stock*/
    double minPDate = -1;
    double maxSDate = -1;
    double TPL = 0;
    for (auto &&r : _records) {
        if (r.getCompany() == symbol) {

            TPL += r.computeProfitLoss();

            if (r.getPurchaseDate() < minPDate || minPDate < 0) {
                minPDate = r.getPurchaseDate();
            }
            if (r.getSaleDate() > maxSDate || maxSDate < 0){
                maxSDate = r.getSaleDate();
            }
        }
    }

    double investmentDays = (maxSDate - minPDate) / (24 * 60); // 24 hours in a day, 60 minutes in an hour

    return TPL / investmentDays;
}
