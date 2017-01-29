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

    double getPurchaseDate() const { return _purchaseDate; }

    double getPurchasePrice() const { return _purchasePrice; }

    double getPurchaseFee() const { return _purchaseFee; }

    double getSaleDate() const { return _saleDate; }

    double getSalePrice() const { return _salePrice; }

    double getSaleFee() const { return _saleFee; }

private:
    std::string _company;

    /* The following data members are stored as doubles rather than ints due to the fact that
     * the integers involved have the potential to be very large. Better safe than sorry.*/
    // TODO: update UML diagram with new double values
    double _numShares;
    double _purchaseDate;
    double _purchasePrice;
    double _purchaseFee;
    double _saleDate;
    double _salePrice;
    double _saleFee;
};


#endif //ANALYSTCOMPARER_PURCHASESALERECORD_H
