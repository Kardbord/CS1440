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
    auto cells = m_cards[cardIndex].getCells();
    for (int i = m_cardSize * m_cardSize; i < m_cards[cardIndex].getCells().size(); ++i) {
        for (int j = 0; j < m_cardSize; ++j) {
            out << cells[i].getVal() << "    ";
        }
        out << std::endl;
    }
}



