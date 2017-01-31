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

    // Initializes data members based on the input file provided in the cmd arguments
    PurchaseSaleRecord(std::ifstream &fin) { load(fin); }

    // Initializes data members based on the input file provided in the cmd arguments
    void load(std::ifstream &fin);

    // Computes the profit/loss for the PurchaseSaleRecord
    int computeProfitLoss();

    std::string getCompany() const { return _company; }

    int getPurchaseDate() const { return _purchaseDate; }

    int getPurchasePrice() const { return _purchasePrice; }

    int getPurchaseFee() const { return _purchaseFee; }

    int getSaleDate() const { return _saleDate; }

    int getSalePrice() const { return _salePrice; }

    int getSaleFee() const { return _saleFee; }

private:
    std::string _company;

    int _numShares;
    int _purchaseDate;
    int _purchasePrice;
    int _purchaseFee;
    int _saleDate;
    int _salePrice;
    int _saleFee;
};


#endif //ANALYSTCOMPARER_PURCHASESALERECORD_H
