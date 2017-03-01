//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int const &cardSize, int const &cardCount, int const &numberMax)
        : m_cardSize(cardSize), m_cardCount(cardCount), m_numberMax(numberMax) {
    for (int i = 0; i < m_cardCount; ++i) {
        m_cards.push_back(Card(m_cardSize, m_numberMax));
    }

    if (numberMax < 10) m_charsPerCell = 5;
    else if (numberMax < 100) m_charsPerCell = 6;
    else if (numberMax < 1000) m_charsPerCell = 7;
    else m_charsPerCell = 8;
    // If numberMax > 10,000, you're playing some weird bingo
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

    printHelper(out, true, false, false); // print the top of the card

    int lineEnd = 1;
    for (auto &&cell : m_cards[cardIndex].getCells()) {
        out << cell.getVal() << " | ";
        if (lineEnd == m_cardSize && cell == m_cards[cardIndex].getCells().back()) {
            printHelper(out, false, true, false); // print the bottom of the card
        } else if (lineEnd == m_cardSize) {
            printHelper(out, false, false, true); // print a spacer
            lineEnd = 1;
        } else {
            ++lineEnd;
        }
    }
}

void Deck::printHelper(std::ostream &out, bool isFirst, bool isLast, bool isSpacer) const {

    if (isFirst) out << "+";
    else if (isLast) out << std::endl << "+";
    else out << std::endl << "|";

    for (int i = 0; i < (m_charsPerCell * m_cardSize) - 2; ++i) {
        out << "-";
    }

    if (isFirst) out << "+" << std::endl << "| ";
    else if (isLast) out << "+" << std::endl;
    else if (isSpacer) out << "|" << std::endl << "| ";
}

