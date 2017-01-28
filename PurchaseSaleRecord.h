//
// Created by Tanner on 1/21/2017.
//

#ifndef ANALYSTCOMPARER_PURCHASESALERECORD_H
#define ANALYSTCOMPARER_PURCHASESALERECORD_H

#include <string>

//TODO add documentation

class PurchaseSaleRecord {
public:
    PurchaseSaleRecord();

    double computeProfitLoss();

    std::string getCompany() { return _company; }

    int getPurchaseDate() { return _purchaseDate; }

    double getPurchasePrice() { return _purchasePrice; }

    double getPurchaseFee() { return _purchaseFee; }

    int getSaleDate() { return _saleDate; }

    double getSalePrice() { return _salePrice; }

    double getSaleFee() { return _saleFee; }

private:
    std::string _company;
    int _purchaseDate;
    double _purchasePrice;
    double _purchaseFee;
    int _saleDate;
    double _salePrice;
    double _saleFee;
};


#endif //ANALYSTCOMPARER_PURCHASESALERECORD_H
