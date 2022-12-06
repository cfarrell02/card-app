//
//  card.hpp
//  cardApp
//
//  Created by Cian Farrell on 02/12/2022.
//

#ifndef card_hpp
#define card_hpp
#include <iostream>
#include <string>

using namespace std;

class Card {
private:
    std::string m_Suit;
    unsigned short m_Value;
public:
    Card(string suit = "Hearts", short value = 1);
    string getSuit();
    string getValue();
    
};

#include <stdio.h>

#endif /* card_hpp */
