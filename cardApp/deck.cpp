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
    vector<Card*>::iterator iterator;
    for(int i = 0; i< d.m_Cards.size(); ++i){
        m_Cards.push_back(new Card(*d.m_Cards[i]));
    }
}

//bool Deck::newDeck(){
//    try{
//        destroyCards();
//        for(string suit : m_Suits){
//            for(int i = 0;i < 13;++i){
//                m_Cards.push_back(new Card(suit,i+1));
//            }
//        }
//        return true;
//    }catch(exception) {
//        return false;
//    }
//}
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
    vector<Card> result;
    for(int i = 0; i< amount ; ++i){
        Card card = *m_Cards.back();
        
       
        result.push_back(card);
        delete m_Cards.back();
        m_Cards.back() = nullptr;
        m_Cards.pop_back();
        
    }
    return result;
}

int Deck::totalCardsInDeck(){
    return (int) m_Cards.size();
}
