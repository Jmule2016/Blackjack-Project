#include "blackjackClass.h"
#include <iostream>
#include <algorithm> //shuffle
#include <chrono> //time
#include <iomanip> //setw
#include <vector> //vectors
using namespace std;


gameDeck::gameDeck()
{
   size = 52;
   deck = new card[size];
   currentCard = 0;
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
   srand((int)time(NULL));
   random_shuffle(&deck[0], &deck[52]);
}

card* gameDeck::draw()
{
   card* ret = NULL;
   if (currentCard < 52)
   {
      ret = &deck[currentCard];
      currentCard++;
   }
   return ret;
}

void game::gameInstructions()
{
   //TODO formatting
   cout << endl 
        << "*************************************************************************************************************************************" << endl
        << "The goal of blackjack is to beat the dealer by getting a count of cards as close to 21 as possible" << endl
        << "without going over 21. Each card is worth its pip value, while Jack, Queen, and King are all worth 10." << endl
        << "An Ace is worth either 1 or 11, determined by the player." << endl << endl
        
        << "The dealer has one face up card and one face down card. The player sees both of his cards and if he has a 10 and an ace" << endl
        << "he has a natural blackjack and beats the dealer unless the dealer also has a natural blackjack." << endl << endl
        
        << "The player decides whether to hit(take another card) or stand(not ask for another card), once the player decides to stand, the dealer" << endl
        << "shows his hidden card and will draw new cards until his count is 17 or above. In the case of the dealer having an ace bringing his" << endl
        << "current hand value to 17 or more, the ace is treated as an 11 and the dealer will stand." << endl << endl
        
        << "If the players hand beats the dealers or the dealer busts, the player wins. If the player busts or his hand has a lower value" << endl
        << "than the dealers, he loses. In the case of a natural blackjack, it is an automatic win unless the opposition has also has" << endl
        << "a natural blackjack. A tie is possible." << endl
        << "*************************************************************************************************************************************" << endl
        << endl;

}

void game::gameMenu()
{
   cout << "Welcome to the game of Blackjack." << endl;
   do
   {
      int menuChoice = 0;
      cout << "Enter the number of your selection from the list below:" << endl;
      cout << "1)" << setw(8) << "Play Blackjack" << endl;
      cout << "2)" << setw(8) << "Instructions" << endl;
      cout << "3)" << setw(8) << "Exit Game" << endl;
      cin >> menuChoice;
      if (menuChoice == 1)
      {
         playGame();
      }
      if (menuChoice == 2)
      {
         gameInstructions();
      }
      if (menuChoice == 3)
      {
         gameExit = 1;
      }
      if(menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
      {
         cout << "Invalid selection, please choice select between 1 and 3." << endl << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   } while (gameExit != 1);
}

void game::hitDealer(bool verbose)
{
   if (verbose)
   {
      cout << "Dealer hits." << endl;
   }
   card* newCard = Deck1.draw();
   if (newCard != NULL)
   {
      dealerHand.push_back(newCard);
   }
}

void game::hitPlayer(bool verbose)
{
   if (verbose)
   {
      cout << "Player hits." << endl;
   }
   card* newCard = Deck1.draw();
   if (newCard != NULL)
   {
      playerHand.push_back(newCard);
   }
}

void game::showCards()
{
   cout << "Dealerhand: " << dealerCount() << endl;
   for (unsigned int i = 0; i < dealerHand.size(); i++)
   {
      dealerHand[i]->display();
   }
   cout << endl;

   cout << "Playerhand: " << playerCount() << endl;
   for (unsigned int i = 0; i < playerHand.size(); i++)
   {
      playerHand[i]->display();
   }
   cout << endl;

}

void game::resetGame()
{
   Deck1.shuffle();
   playerHand.clear();
   dealerHand.clear();
}

int game::dealerCount()
{
   int ret = 0;
   for (unsigned int i = 0; i < dealerHand.size(); i++)
   {
      ret += dealerHand[i]->getValue();
   }
   return ret;
}

int game::playerCount()
{
   int ret = 0;
   for (unsigned int i = 0; i < playerHand.size(); i++)
   {
      ret += playerHand[i]->getValue();
   }
   return ret;

}



void game::playGame()
{
   resetGame();
   hitDealer(false);
   hitPlayer(false);
   hitDealer(false);
   hitPlayer(false);

   showCards();
   while (dealerCount() < 17)
   {
      hitDealer(true);
      showCards();
   }

   int hit = 1;
   while (hit == 1 && playerCount() < 21)
   {
      cout << "Would you like to hit(1 or 0)? ";
      cin  >> hit;
      cout << endl;
      if (hit == 1)
      {
         hitPlayer(true);
         showCards();
      }

   }
}

gameDeck::~gameDeck()
{
   delete[] deck;
}