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

    bool profitOrLoss();

    std::string getCompany() { return _company; }

    int getPurchaseDate() { return _purchaseDate; }

    double getPurchasePrice() { return _purchasePrice; }

    double getPurchaseTransFee() { return _purchaseTransFee; }

    int getSaleDate() { return _saleDate; }

    double getSalePrice() { return _salePrice; }

    double getSaleTransFee() { return _saleTransFee; }

private:
    std::string _company;
    int _purchaseDate;
    double _purchasePrice;
    double _purchaseTransFee;
    int _saleDate;
    double _salePrice;
    double _saleTransFee;
};


#endif //ANALYSTCOMPARER_PURCHASESALERECORD_H
