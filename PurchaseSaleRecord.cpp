//
// Created by Tanner on 1/21/2017.
// A02052217
//

//TODO add documentation

#include "PurchaseSaleRecord.h"
#include "Utils.h"

// Initializes data members based on the input file provided in the cmd arguments
void PurchaseSaleRecord::load(std::ifstream &fin) {
    std::getline(fin, _company, ',');
    _company = ltrim(_company);
    _company = rtrim(_company);

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
double PurchaseSaleRecord::computeProfitLoss() {
    double totInvestment = (_numShares * _purchasePrice) + _purchaseFee + _saleFee;

    return (_numShares * _salePrice) - totInvestment;
}
