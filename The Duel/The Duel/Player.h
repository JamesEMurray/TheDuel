#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

class Player
{
public:
	short card1 = 14;
	short card2 = 14;
	short card3 = 14;
	short handSize;
	short numTricks;
	short chosenCard; //for playerPlay()
	short pChoice; //numeric value of card played

	//special cards values
	short Ace = 0;
	short Jack = 11;
	short Queen = 12;
	short King = 13;

	//functions
	void drawCard(); //draws card to replace played card
	void playerPlay(); //plays card based on user input
	int getRandNum(int t_lowest, int t_highest); //generates a random number
	void showHand(); //displays players hand

private:

};