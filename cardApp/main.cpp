//
//  main.cpp
//  cardApp
//
//  Created by Cian Farrell on 02/12/2022.
//

#include <iostream>
#include "card.hpp"
#include "deck.hpp"

void dealCards(Deck* deck);
int main(int argc, const char * argv[]) {
    cout<<"Welcome to the card app!!"<<endl;
    cout<<"----"<<endl;
    Deck deck;
    while (true) {
        int choice;
        cout<<"What would you like to do..."<<endl;
        cout<<"1. View current deck "<<endl;
        cout<<"2. Get a new deck "<<endl;
        cout<<"3. Shuffle the deck of cards "<<endl;
        cout<<"4. Deal a specified amount of cards "<<endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout<<deck.listCardsInDeck()<<endl;
                break;
            case 2:
                deck.newDeck();
                cout<<"A new deck has been acquired";
                break;
            case 3:
                deck.shuffleCards();
                cout<<"The deck has been shuffled";
                break;
            case 4:
                dealCards(&deck);
            default:
                cout<<"Exiting..."<<endl;
                return 0;
                break;
        }
        
        
    }
    return 0;
}

void dealCards(Deck* deck){
    int amount;
    cout<<"How many cards would you like dealt? ";
    cin >> amount;
    vector<Card> cards = deck->deal(amount);
    cout<<"Dealing cards..."<<endl;
    for(Card card: cards){
        cout<< card.getValue() <<" of "<< card.getSuit()<<endl;
    }
}
