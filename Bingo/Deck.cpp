//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int const &cardSize, int const &cardCount, int const &numberMax)
        : m_cardSize(cardSize), m_cardCount(cardCount), m_numberMax(numberMax) {
    for (int i = 0; i < m_cardCount; ++i) {
        m_cards.push_back(Card(m_cardSize, m_numberMax));
    }
}

Deck::~Deck() {
    // TODO: Verify correct implementation
    m_cards.clear();
    m_cards.shrink_to_fit();
}

void Deck::print(std::ostream &out) const {
    // TODO: Implement
}

void Deck::print(std::ostream &out, int cardIndex) const {
    int lineEnd = 1;
    for (auto && cell : m_cards[cardIndex].getCells()){
        out << cell.getVal() << "----";
        if (lineEnd == m_cardSize){
            out << std::endl;
            lineEnd = 1;
        }
        else {
            ++lineEnd;
        }
    }

}

