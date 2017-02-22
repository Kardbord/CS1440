//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int cardSize, int cardCount, int numberMax)
        : m_cardSize(cardSize), m_cardCount(cardCount), m_numberMax(numberMax) {}

Deck::~Deck() {
    // TODO: Verify correct implementation
    m_cards.clear();
    m_cards.shrink_to_fit();
}

void Deck::print(std::ostream &out) const {
    // TODO: Implement
}

void Deck::print(std::ostream &out, int cardIndex) const {
    // TODO: Implement
}



