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