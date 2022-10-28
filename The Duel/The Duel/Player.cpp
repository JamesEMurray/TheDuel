#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include <random>
#include <time.h>

void Player::drawCard() //draws card to replace played card
{
	//Make rand() truly random
	std::srand(static_cast<unsigned>(time(nullptr)));

	if (card1 == 14)
	{
		card1 = getRandNum(0, 13); //assigns value between 0-13
		handSize++;
	}

	if (card2 == 14)
	{
		card2 = getRandNum(0, 13); //assigns value between 0-13
		handSize++;
	}

	if (card3 == 14)
	{
		card3 = getRandNum(0, 13); //assigns value between 0-13
		handSize++;
	}

	showHand();
}

void Player::playerPlay() //plays card based on user input
{
	//local variables
	bool choiceMade = false;

	while (choiceMade == false)
	{
		//get user input
		std::cout << "Please select the card you wish to play (1/2/3)" << std::endl;
		std::cin >> chosenCard;

		switch (chosenCard)
		{
		case 1:
			pChoice = card1;
			card1 = 14;
			choiceMade = true;
			break;
		case 2:
			pChoice = card2;
			card2 = 14;
			choiceMade = true;
			break;
		case 3:
			pChoice = card3;
			card3 = 14;
			choiceMade = true;
			break;
		default:
			std::cout << "You must choose a value between 1-3" << std::endl;
			break;
		}
	}

	handSize--;
	
}

int Player::getRandNum(int t_lowest, int t_highest)
{
	//declare variable necessary for process
	int range = t_highest - t_lowest + 1;
	int answer = std::rand() % range;

	//calc answer
	answer = answer + t_lowest;

	return answer;
}

void Player::showHand() //display players hand
{
	//local variables
	char c1;
	char c2;
	char c3;

	if (card1 == 0 || card1 >= 10) //card1 special cases A=0 , J=11 , Q=12 , K=13
	{
		if (card1 == Ace)
		{
			c1 = 'A';
		}
		else if (card1 == 10)
		{
			c1 = '0';
		}
		else if (card1 == Jack)
		{
			c1 = 'J';
		}
		else if (card1 == Queen)
		{
			c1 = 'Q';
		}
		else
		{
			c1 = 'K';
		}
	}
	else
	{
		c1 = (char)(card1 + 48);
	}

	if (card2 == 0 || card2 >= 10) //card2 special cases  A=0 , J=11 , Q=12 , K=13
	{
		if (card2 == Ace)
		{
			c2 = 'A';
		}
		else if (card2 == 10)
		{
			c2 = '0';
		}
		else if (card2 == Jack)
		{
			c2 = 'J';
		}
		else if (card2 == Queen)
		{
			c2 = 'Q';
		}
		else
		{
			c2 = 'K';
		}
	}
	else
	{
		c2 = (char)(card2 +48);
	}
	
	if (card3 == 0 || card3 >= 10) //card3 special cases  A=0 , J=11 , Q=12 , K=13
	{
		if (card3 == Ace)
		{
			c3 = 'A';
		}
		else if (card3 == 10)
		{
			c3 = '0';
		}
		else if (card3 == Jack)
		{
			c3 = 'J';
		}
		else if (card3 == Queen)
		{
			c3 = 'Q';
		}
		else
		{
			c3 = 'K';
		}
	}
	else
	{
		c3 = (char)(card3 + 48);
	}

	std::cout << "Hand: " << c1 << " , " << c2 << " , " << c3 << std::endl;
	std::cout << "Cards in hand: " << handSize << std::endl;
}