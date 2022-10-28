//Name: James Murray (C00272116)
//Date: 28/10/22
//Programme Purpose: Play a game named 'The Duel' that uses aspects of polymorphism
//Known Bugs/Errors: 1) In the showdown it displays actual number rather than A,J,Q,K for special characters

#include <iostream>
#include "Game.h"
#include "AI.h"
#include "Player.h"

Game game; //game object
AI ai; //ai object
Player player; //player object

int main()
{
	game.welcomeMsg();

	while (player.numTricks < 3 && ai.aiNumTricks < 3)
	{
		game.nextTurn();

		player.playerPlay();
		ai.playCard();

		game.winRLose();
		game.updateScore();
	}

	return 0;
}

void Game::welcomeMsg() //displays a welcome message
{
	std::cout << "Welcome to The Duel!" << std::endl;
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; //standard window width 122 chars
}

void Game::nextTurn() //starts the next turn
{
	turnCount++;

	if (turnCount == 1)
	{
		std::cout << "How To Play:" << std::endl << std::endl;
		std::cout << "On your turn, type 1, 2 OR 3. This will then play card1, card2 or card3 from your hand." << std::endl;
		std::cout << "Your opponent will then play their card." << std::endl;
		std::cout << "The player with the higher value card wins the trick." << std::endl;
		std::cout << "The first to win 3 tricks slays their opponent. Now, let's get to some dueling!" << std::endl;
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; //standard window width 122 chars
	}
	else
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; //standard window width 122 chars

	}

	std::cout << "Turn: " << turnCount << std::endl; //displays turn count

	if (player.handSize < 3)
	{
		//std::cout << "Cards in hand: " << player.handSize << std::endl; //test that hand size is correct
		std::cout << "\nDraw!\n" << std::endl;
	}
	player.drawCard();
	ai.aiDrawCard();
}

void Game::winRLose() //checks card values against one another
{
	std::cout << player.pChoice << " vs " << ai.aiChoice << "\n" << std::endl;

	if (player.pChoice > ai.aiChoice)
	{
		switch (player.numTricks + 1)
		{
		case 1:
			std::cout << "\nYou strike true and slash your enemy. They look slightly injured.\n" << std::endl;
			break;
		case 2:
			std::cout << "\nYou deliver a devistating blow to your enemy. They look badly injured.\n" << std::endl;
			break;
		case 3:
			std::cout << "\nYou slice toward your foe in a blazing arc. Your enemy lets out one last deathrattle, then they are slain.\n" << std::endl;
			break;
		}

		player.numTricks++;
		
	}
	else if (player.pChoice == ai.aiChoice)
	{
		std::cout << "\nBoth you and your foe strike and parry with such efficiency that neither of you gets the upper hand.\n" << std::endl;
	}
	else if (player.pChoice < ai.aiChoice)
	{
		switch (ai.aiNumTricks + 1)
		{
		case 1:
			std::cout << "\nDespite your best efforts, your opponent finds a way around your defence. 'Tis merely a flesh wound'.\n" << std::endl;
			break;
		case 2:
			std::cout << "\nAgain your enemy harrys you and strikes past your guard. 'They merely a bad flesh wound'.\n" << std::endl;
			break;
		case 3:
			std::cout << "\nFoolishly, you laugh as your opponent unscrews their pommel. They end you rightly\n" << std::endl;
			break;
		}

		ai.aiNumTricks++;
	}
}

void Game::updateScore() //updates score according to winRLose()
{
	std::cout << "\nNumber of Tricks:\n" << "Player: " << player.numTricks << "\n" << "Opponent: " << ai.aiNumTricks << std::endl;
}