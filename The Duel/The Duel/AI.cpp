#include <iostream>
#include <stdlib.h>
#include "AI.h"

void AI::aiDrawCard() //draws card to replace played card
{
	//Make rand() truly random
	std::srand(static_cast<unsigned>(time(nullptr)));

	if (card1 == 14)
	{
		card1 = getRandNum(0, 13); //assigns value between 0-13
	}

	if (card2 == 14)
	{
		card2 = getRandNum(0, 13); //assigns value between 0-13
	}

	if (card3 == 14)
	{
		card3 = getRandNum(0, 13); //assigns value between 0-13
	}
}

void AI::playCard() //plays card based on result of randomiser
{
	//Make rand() truly random
	std::srand(static_cast<unsigned>(time(nullptr)));

	//local variables
	int switchboard = getRandNum(1, 3);

	switch (switchboard)
	{
	case 1:
		aiChoice = card1;
		card1 = 14;
		break;
	case 2:
		aiChoice = card2;
		card2 = 14;
		break;
	case 3:
		aiChoice = card3;
		card3 = 14;
		break;
	}
}

int AI::getRandNum(int t_lowest, int t_highest)
{
	//declare variable necessary for process
	int range = t_highest - t_lowest + 1;
	int answer = std::rand() % range;

	//calc answer
	answer = answer + t_lowest;

	return answer;
}