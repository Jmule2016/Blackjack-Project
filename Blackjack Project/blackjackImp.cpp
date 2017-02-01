#include "blackjackClass.h"
#include <iostream>
#include <algorithm> //shuffle
#include <chrono> //system_clock
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
      }
   }
}

void gameDeck::display()
{
   for (unsigned int cur_suit = 0; cur_suit < NUM_SUITS; cur_suit++)
   {
      for (unsigned int card_num = 0; card_num < NUM_CARDS_PER_SUIT; card_num++)
      {
         deck[cur_suit * NUM_CARDS_PER_SUIT + card_num].display();
      }
   }
}

void gameDeck::shuffle()
{
   srand(time(NULL));
   random_shuffle(&deck[0], &deck[51]);
}

void game::gameInstructions()
{
   cout << "Placeholder" << endl;
}

void game::playGame()
{
   gameDeck Deck1;
   Deck1.shuffle();
   Deck1.display();
}

gameDeck::~gameDeck()
{
   delete[] deck;
}