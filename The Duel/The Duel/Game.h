#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

class Game
{
public:
	const short MaxHandSize = 3;
	short turnCount;

	//functions
	void welcomeMsg(); //displays a welcome message
	void nextTurn(); //starts the next turn
	void winRLose(); //checks card values against one another
	void updateScore(); //updates score according to winRLose()

private:

};