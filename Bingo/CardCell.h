//
// Created by Tanner on 2/21/2017.
//

#ifndef BINGO_CARDCELL_H
#define BINGO_CARDCELL_H


class CardCell {
public:
    CardCell(int const &val);

    int getVal() const { return m_val; }

    bool operator==(CardCell const &c) const;

private:
    int m_val;
};


#endif //BINGO_CARDCELL_H
