//
//  card.cpp
//  cardApp
//
//  Created by Cian Farrell on 02/12/2022.
//

#include "card.hpp"

Card::Card(string suit, short value):
    m_Suit(suit) , m_Value(value)
{
    
}

string Card::getSuit(){
    return m_Suit;
}

string Card::getValue(){
    string result;
    switch (m_Value) {
        case 1:
            result = "Ace";
            break;
        case 11:
            result = "Jack";
            break;
        case 12:
            result = "Queen";
            break;
        case 13:
            result = "King";
        default:
            result = std::to_string(m_Value);
            break;
    }
    return result;
}

