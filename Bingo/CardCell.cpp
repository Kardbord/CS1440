//
// Created by Tanner on 2/21/2017.
//

#include "CardCell.h"

CardCell::CardCell(int const & val) : m_val(val) {}

bool CardCell::operator==(CardCell const &c) const {
    return c.getVal() == this->getVal();
}
