//
// Created by Tanner on 1/21/2017.
//

//TODO add documentation

#include "PurchaseSaleRecord.h"

// Initializes data members based on the input file provided in the cmd arguments
void PurchaseSaleRecord::load(std::ifstream &fin) {
    std::getline(fin, _company, ',');

    std::string shares;
    std::getline(fin, shares, ',');
    _numShares = std::stoi(shares);

    std::string pDate;
    std::getline(fin, pDate, ',');
    _purchaseDate = std::stoi(pDate);

    std::string pPrice;
    std::getline(fin, pPrice, ',');
    _purchasePrice = std::stoi(pPrice);

    std::string pFee;
    std::getline(fin, pFee, ',');
    _purchaseFee = std::stoi(pFee);

    std::string sDate;
    std::getline(fin, sDate, ',');
    _saleDate = std::stoi(sDate);

    std::string sPrice;
    std::getline(fin, sPrice, ',');
    _salePrice = std::stoi(sPrice);

    fin >> _saleFee;
}

// Computes the profit/loss for the PurchaseSaleRecord
int PurchaseSaleRecord::computeProfitLoss() {
    int totInvestment = (_numShares * _purchasePrice) + _purchaseFee + _saleFee;

    return (_numShares * _salePrice) - totInvestment;
}
