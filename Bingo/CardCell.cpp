//
// Created by Tanner on 2/21/2017.
//

#include <iostream>
#include "CardCell.h"

CardCell::CardCell(int const & val) : m_val(val) {}

bool CardCell::operator==(CardCell const &c) {
    return c.getVal() == this->getVal();
}
