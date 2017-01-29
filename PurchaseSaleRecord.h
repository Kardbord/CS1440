//
// Created by Tanner on 1/21/2017.
//

#ifndef ANALYSTCOMPARER_PURCHASESALERECORD_H
#define ANALYSTCOMPARER_PURCHASESALERECORD_H

#include <string>
#include <fstream>

//TODO add documentation

class PurchaseSaleRecord {
public:
    PurchaseSaleRecord() {}

    PurchaseSaleRecord(std::ifstream &fin) { load(fin); }

    void load(std::ifstream &fin);

    double computeProfitLoss();

    std::string getCompany() { return _company; } const

    int getPurchaseDate() { return _purchaseDate; } const

    double getPurchasePrice() { return _purchasePrice; } const

    double getPurchaseFee() { return _purchaseFee; } const

    int getSaleDate() { return _saleDate; } const

    double getSalePrice() { return _salePrice; } const

    double getSaleFee() { return _saleFee; } const

private:
    std::string _company;
    int _numShares;
    int _purchaseDate;
    int _purchasePrice;
    int _purchaseFee;
    int _saleDate;
    double _salePrice;
    double _saleFee;
};


#endif //ANALYSTCOMPARER_PURCHASESALERECORD_H
