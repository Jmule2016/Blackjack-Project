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
   cout << "Placeholder" << endl;
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

   } while (gameExit = 0);
   //Deck1.display();
}

gameDeck::~gameDeck()
{
   delete[] deck;
}