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
            m_Cards.push_back(new Card(suit,i+1));
        }
    }
}

Deck::~Deck(){
    vector<Card*>::iterator iterator;
    for(iterator = m_Cards.begin(); iterator != m_Cards.end();++iterator){
        delete *iterator;
        *iterator = nullptr;
    }
    m_Cards.clear();
}

Deck::Deck(const Deck& d){
    for(int i = 0; i< d.m_Cards.size(); ++i){
        m_Cards.push_back(new Card(*d.m_Cards[i]));
    }
}

Deck& Deck::operator=(const Deck& d){
    if (this != &d) {
        for(int i = 0; i< m_Cards.size(); ++i){
            delete m_Cards[i];
            m_Cards[i] = new Card(*d.m_Cards[i]);
        }
        (*m_Suits) = (*d.m_Suits);
        
    }
    return *this;
}

void Deck::shuffleCards(){
    shuffle(m_Cards.begin(),m_Cards.end(),default_random_engine(static_cast<unsigned int>(time(0))));
}

string Deck::listCardsInDeck(){
    stringstream result;
    for(vector<Card*>::iterator iterator = m_Cards.begin(); iterator != m_Cards.end();++iterator){
        result<<(*iterator)->getValue() << " of " << (*iterator)->getSuit()<< '\n';
    }
    return result.str();
}
vector<Card> Deck::deal(int amount){
    if(amount > m_Cards.size()) throw exception();
    vector<Card> result;
    for(int i = 0; i< amount ; ++i){
        Card card = *m_Cards.back();
        
        result.push_back(card);
        
        // Delete the Card object and remove it from the m_Cards vector
        delete m_Cards.back();
        m_Cards.pop_back();
    }
    return result;
}


int Deck::totalCardsInDeck(){
    return (int) m_Cards.size();
}
