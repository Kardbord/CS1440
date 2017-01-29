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

    std::string getCompany() const { return _company; }

    int getPurchaseDate() const { return _purchaseDate; }

    double getPurchasePrice() const { return _purchasePrice; }

    double getPurchaseFee() const { return _purchaseFee; }

    int getSaleDate() const { return _saleDate; }

    double getSalePrice() const { return _salePrice; }

    double getSaleFee() const { return _saleFee; }

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
