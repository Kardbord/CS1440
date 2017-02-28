//
// Created by Tanner on 2/21/2017.
//

#include <iostream>
#include "CardCellTester.h"
#include "../CardCell.h"

void CardCellTester::testGetVal() {
    std::cout << std::endl << "Test Suite: CardCellTester::testGetVal" << std::endl;

    CardCell cell1(50);

    if (cell1.getVal() != 50) {
        std::cout << "Error in cell1.getVal: should be 50" << std::endl;
    }

    CardCell cell2(0);

    if (cell2.getVal() != 0) {
        std::cout << "Error in cell2.getVal: should be 50" << std::endl;
    }

    CardCell cell3(-50);

    if (cell3.getVal() != -50) {
        std::cout << "Error in cell3.getVal: should be -50" << std::endl;
    }
}

void CardCellTester::testOperatorOverloads() {
    std::cout << std::endl << "Test Suite: CardCellTester::testOperatorOverloads" << std::endl;

    CardCell cell(12);
    if (!(cell == cell)) {
        std::cout << "Error in cell == cell, should be equal" << std::endl;
    }

    CardCell cell2(12);
    if (!(cell == cell2)) {
        std::cout << "Error in cell == cell2, should be equal" << std::endl;
    }

    CardCell cell3(20);
    if (cell == cell3) {
        std::cout << "Error in cell == cell3, should not be equal" << std::endl;
    }
}