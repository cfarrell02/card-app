//
//  main.cpp
//  cardApp
//
//  Created by Cian Farrell on 02/12/2022.
//

#include <iostream>
#include "card.hpp"
#include "deck.hpp"

void dealCards(Deck* deck), newDeck(Deck* deck);
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
        cout<<"Press 0 to exit"<<endl;
        cout<<">";
        cin >> choice;
        switch (choice) {
            case 0:
                cout<<"Exiting..."<<endl;
                return 0;
            case 1:
                cout<<deck.listCardsInDeck()<<endl;
                break;
            case 2:
                deck = Deck();
                cout<<"A new deck has been acquired";
                break;
            case 3:
                deck.shuffleCards();
                cout<<"The deck has been shuffled";
                break;
            case 4:
                dealCards(&deck);
                break;
            default:
                cout<<"Invalid Option"<<endl;
                break;
        }
        
        
    }
    return 0;
}

void dealCards(Deck* deck){
    int amount;
    cout<<"How many cards would you like dealt? ";
    cin >> amount;
    cout<<"Dealing cards..."<<endl;
    vector<Card> results = deck->deal(amount);
    for(int i = 0 ;i < amount;++i){
        cout<<results[i].getValue()<<" of "<<results[i].getSuit()<<"\n";
    }
}
