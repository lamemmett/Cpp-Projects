//	AssassinManager Game
//		This file defines the menu interactions and game behavior of the Assassin Manager game

#include "stdafx.h"
#include "AssassinManager.h"
#include <string>
#include <iostream>
#include <list>

int main()
{
	using namespace std;

	bool playAgain = true;

	while (playAgain) {
		int numPlayers;
		std::list<std::string> names;

		// Get number of players from user
		cout << "How many players? (min 2) ";
		cin >> numPlayers;

		// Ensure min of 2 players
		while (numPlayers < 2) {
			cout << "How many players? (min 2) ";
			cin >> numPlayers;
		}

		// Query for each player name
		for (int i = 0; i < numPlayers; i++) {
			std::string name;
			cout << "Player " << i + 1 << " name: ";
			cin >> name;
			names.push_back(name);
		}

		AssassinManager* game = new AssassinManager(names);

		cout << "Welcome to Assassin\n\n";

		// Kill names until one player left
		while (!game->gameOver()) {
			std::string name;

			cout << "Current kill ring:\n";
			game->printKillRing();
			cout << "Current graveyard:\n";
			game->printGraveyard();
			cout << "\n";

			do {
				cout << "next victim? ";
				cin >> name;
			} while (!game->killRingContains(name));

			game->kill(name);
		}

		// Report winner when done
		cout << "Game was won by " << game->winner() << "\n";
		cout << "Final graveyard is as follows:\n";
		game->printGraveyard();

		// Prompt to play again
		std::string tempBuff;
		cout << "Play again? (y/n) ";
		cin >> tempBuff;
		if (tempBuff.compare("y") == 0 || tempBuff.compare("Y") == 0) {
			names.clear();
		}
		else {
			playAgain = false;
		}
	}
}