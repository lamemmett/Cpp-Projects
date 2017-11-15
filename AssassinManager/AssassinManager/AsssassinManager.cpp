//	AssassinManager.cpp
//		This file defines the member functions of the AssassinManager class

#include "stdafx.h"
#include <iostream>
#include "AssassinManager.h"

using namespace std;

// Constructor
AssassinManager::AssassinManager(std::list<std::string> names) {
	if (names.empty()) {
		throw std::invalid_argument("Empty name list");
	}

	names.reverse();

	while (!names.empty()) {
		AssassinManager::killRing = new AssassinNode(names.front(), AssassinManager::killRing);
		names.pop_front();
	}
}

// Prints list of alive players and their respective targets
void AssassinManager::printKillRing() {
	AssassinNode* current = AssassinManager::killRing;

	while (current != NULL) {
		cout << "    " << current->name << " is stalking ";
		if (current->next != NULL) {
			cout << current->next->name << '\n';
		}
		else {
			cout << killRing->name << '\n';
		}
		current = current->next;
	}
}

// Prints the list of dead players and who killed them
void AssassinManager::printGraveyard() {
	AssassinNode* current = AssassinManager::graveyard;

	while (current != NULL) {
		cout << "    " << current->name << " was killed by " << current->killer << '\n';
		current = current->next;
	}
}

// Returns whether the requested player is alive
bool AssassinManager::killRingContains(std::string name) {
	AssassinNode* current = AssassinManager::killRing;

	while (current != NULL) {
		if (name.compare(current->name) == 0) {
			return true;
		}
		current = current->next;
	}

	return false;
}

// Returns whether the requested player is dead
bool AssassinManager::graveyardContains(std::string name) {

	AssassinNode* current = AssassinManager::graveyard;

	while (current != NULL) {
		if (name.compare(current->name) == 0) {
			return true;
		}
		current = current->next;
	}

	return false;
}

// Returns whether game has ended
bool AssassinManager::gameOver() {
	return AssassinManager::killRing->next == NULL;
}

// Returns name of winner if the game has ended
std::string AssassinManager::winner() {
	if (gameOver()) {
		return AssassinManager::killRing->name;
	}
	
	return NULL;
}

// Kills a player from the list of alive players
//	- Throws an error if the requested name is not alive
//	- Throws an error if the game has already ended
void AssassinManager::kill(std::string name) {
	if (!AssassinManager::killRingContains(name)) {
		throw std::invalid_argument("Name not found in killRing");
	}
	else if (AssassinManager::gameOver()) {
		throw std::logic_error("Illegal game state");
	}
	else {
		AssassinNode* current = killRing;

		// Edge case: first name on list
		if (current->name.compare(name) == 0) {
			killRing = current->next;
			current->next = graveyard;
			graveyard = current;

			// Find name of killer (end of killRing)
			current = killRing;
			while (current != NULL) {
				if (current->next == NULL) {
					graveyard->killer = current->name;
				}
				current = current->next;
			}
			return;
		}

		while (current != NULL) {
			// Find node stalking the given name
			if (current->next != NULL && current->next->name.compare(name) == 0) {
				// Track node to remove
				AssassinNode* temp = current->next;
				temp->killer = current->name;

				current->next = temp->next;
				temp->next = graveyard;
				graveyard = temp;
			}

			current = current->next;
		}
	}
}