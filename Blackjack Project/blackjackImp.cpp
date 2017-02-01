#include "blackjackClass.h"
#include <iostream>
#include <algorithm> //shuffle
#include <chrono> //time
#include <iomanip> //setw
using namespace std;


gameDeck::gameDeck()
{
   size = 52;
   deck = new card[size];
   for (unsigned int cur_suit = 0; cur_suit < NUM_SUITS; cur_suit++)
   {
      for (unsigned int card_num = 0; card_num < NUM_CARDS_PER_SUIT; card_num++)
      {
         deck[cur_suit * NUM_CARDS_PER_SUIT + card_num].set(card_num, (suit_e)cur_suit);
         //sets value and suit for every card
      }
   }
}

void gameDeck::display()
{
   //TODO change function to display current cards 
   for (unsigned int cur_suit = 0; cur_suit < NUM_SUITS; cur_suit++)
   {
      for (unsigned int card_num = 0; card_num < NUM_CARDS_PER_SUIT; card_num++)
      {
         deck[cur_suit * NUM_CARDS_PER_SUIT + card_num].display();
         //displays every card
      }
   }
}

void gameDeck::shuffle() //function shuffles all 52 cards
{
   srand(time(NULL));
   random_shuffle(&deck[0], &deck[52]);
}

void game::gameInstructions()
{
   //TODO create game instructions
   cout << "The goal of blackjack is to beat the dealer by getting a count of cards as close to 21 as possible" << endl
        << "without going over 21. Each card is worth its pip value, while Jack, Queen, and King are all worth 10." << endl
        << "An Ace is worth either 1 or 11, determined by the player." << endl << endl
        
        << "The dealer has one face up card and one face down card. The player sees both of his cards and if he has a 10 and an ace" << endl
        << "he has a natural blackjack and beats the dealer unless the dealer also has a natural blackjack." << endl << endl
        
        << "The player decides whether to hit(take another card) or stand(not ask for another card), once the player decides to stand, the dealer" << endl
        << "shows his hidden card and will draw new cards until his count is 17 or above. In the case of the dealer having an ace bringing his" << endl
        << "current hand value to 17 or more, the ace is treated as an 11 and the dealer will stand." << endl << endl
        
        << "If the players hand beats the dealers or the dealer busts, the player wins. If the player busts or his hand has a lower value" << endl
        << "than the dealers, he loses. In the case of a natural blackjack, it is an automatic win unless the opposition has also has" << endl
        << "a natural blackjack. A tie is possible." << endl;

}

int game::gameMenu()
{
   int menuChoice;
   cout << "Enter the number of your selection from the list below:" << endl;
   cout << "1) " << setw(10) << "Play Blackjack" << endl;
   cout << "2) " << setw(10) << "Instructions" << endl;
   cout << "3) " << setw(10) << "Exit Game" << endl;
   cin  >> menuChoice;
   while (menuChoice == 0 || menuChoice >= 4)
   {
      cout << "Invalid selection, please choice select between 1 and 3." << endl;
      cin  >> menuChoice;
   }
   return menuChoice;
}

void game::playGame()
{
   cout << "Welcome to the game of Blackjack." << endl;
   do
   {
      gameDeck Deck1;
      Deck1.shuffle();
      gameInstructions();

   } while (gameExit = 0);
   //Deck1.display();
}

gameDeck::~gameDeck()
{
   delete[] deck;
}