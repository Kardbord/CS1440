//
// Created by Tanner on 2/21/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H


class Card {

public:
    Card(int cardSize, int numberMax);

    int getCardSize() { return m_cardSize; }

    int getNumberMax() { return m_numberMax; }

private:
    int m_cardSize;
    int m_numberMax;
};


#endif //BINGO_CARD_H
