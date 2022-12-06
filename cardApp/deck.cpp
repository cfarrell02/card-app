//
//  deck.cpp
//  cardApp
//
//  Created by Cian Farrell on 02/12/2022.
//

#include "deck.hpp"


Deck::Deck(){
    for(string suit : m_Suits){
        for(int i = 0;i < 13;++i){
            m_Cards->push_back(new Card(suit,i+1));
        }
    }
}

void Deck::destroyCards(){
    vector<Card*>::iterator iterator;
    for(iterator = m_Cards->begin(); iterator != m_Cards->end();++iterator){
        delete *iterator;
        *iterator = nullptr;
    }
    m_Cards->clear();
}

bool Deck::newDeck(){
    try{
        destroyCards();
        for(string suit : m_Suits){
            for(int i = 0;i < 13;++i){
                m_Cards->push_back(new Card(suit,i+1));
            }
        }
        return true;
    }catch(exception) {
        return false;
    }
}
inline void Deck::shuffleCards(){
    shuffle(m_Cards->begin(),m_Cards->end(),default_random_engine(static_cast<unsigned int>(time(0))));
}

string Deck::listCardsInDeck(){
    stringstream result;
    for(vector<Card*>::iterator iterator = m_Cards->begin(); iterator != m_Cards->end();++iterator){
        result<<"Suit: "+(*iterator)->getSuit() + " Value: " << (*iterator)->getValue() << "\n";
    }
    return result.str();
}
vector<Card> Deck::deal(int amount){
    vector<Card> results;
    for(int i = 0; i< amount ; ++i){
        vector<Card*>::iterator iter;
        iter = m_Cards->end();
        m_Cards->pop_back();
        results.push_back(**iter);
        delete *iter;
        *iter = nullptr;
    }
    return results;
}

int Deck::totalCardsInDeck(){
    return m_Cards->size();
}
