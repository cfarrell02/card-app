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

short Card::getValue(){
    enum values {Ace = 1, Jack = 11, Queen, King};
    std::cout<<(values)m_Value<<std::endl;
    return m_Value;
}

