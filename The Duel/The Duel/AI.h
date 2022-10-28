#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

class AI
{
public:
	short card1 = 14;
	short card2 = 14;
	short card3 = 14;
	short aiNumTricks;
	short aiChoice;

	//functions
	void aiDrawCard(); //draws card to replace played card
	void playCard(); //plays card based on result of randomiser
	int getRandNum(int t_lowest, int t_highest); //generates a random number

private:

};