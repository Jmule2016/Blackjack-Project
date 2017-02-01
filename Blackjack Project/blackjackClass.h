#ifndef BLACKJACK_IMPLEMENT_CPP
#define BLACKJACK_IMPLEMENT_CPP

#include <iostream>
#include <string>

using namespace std;

enum suit_e
{
   DIAMONDS,
   HEARTS,
   SPADES,
   CLUBS,

   NUM_SUITS
};

class card
{
public:
   void set(int in_value, suit_e in_suit) //function sets value and suit of cards
   {
      value = in_value;
      suit = in_suit;
   }
   void display() //switch function for displaying cards
   {
      string suit_str[4] = { "\x04", "\x03", "\x06", "\x05" };
      switch (value)
      {
      case 0:
         cout << "A";
         break;
      case 10:
         cout << "J";
         break;
      case 11:
         cout << "Q";
         break;
      case 12:
         cout << "K";
         break;
      default:
         cout << value + 1;
         break;
      }
      cout << " of " << suit_str[suit] << endl;
   }
   int value;
   suit_e suit;
};


class gameDeck
{
public:
   gameDeck();
   ~gameDeck();
   void shuffle(); //shuffle cards
   void display(); //display cards - temp function
   void draw();    //draw a new card from deck

private:
   int size;
   int currentCard;
   card *deck; //array of cards with a deck size of 52
   static const unsigned int NUM_CARDS_PER_SUIT = 13; //maximum cards per suit
};

class game
{
public:
   void gameMenu();
   void gameInstructions(); //instructions for play
   void playGame(); //main game drive
private:
   bool gameExit;
   int menuSelection;
};
#endif