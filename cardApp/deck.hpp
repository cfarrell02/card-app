//
//  deck.hpp
//  cardApp
//
//  Created by Cian Farrell on 02/12/2022.
//

#ifndef deck_hpp
#define deck_hpp
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include "card.hpp"

class Deck{
private:
    vector<Card*> m_Cards;
    string m_Suits[4] = {"Hearts","Diamonds","Spades","Clubs"};
public:
    Deck();
    Deck(const Deck& d);
    ~Deck();
    Deck& operator=(const Deck& d);
    void shuffleCards();
    string listCardsInDeck();
    vector<Card> deal(int amount);
    int totalCardsInDeck();
    
};
#include <stdio.h>

#endif /* deck_hpp */
