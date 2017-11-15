//	AssassinManager.h
//		This file defines the public interface for the AssassinManager class

#ifndef ASSASSINMANAGER_H
#define ASSASSINMANAGER_H

#include <list>
#include <string>
#include "AssassinNode.h"

class AssassinManager {
private:
	AssassinNode* killRing = NULL;
	AssassinNode* graveyard = NULL;

public:
	AssassinManager::AssassinManager(std::list<std::string> names);
	void printKillRing();
	void printGraveyard();
	bool killRingContains(std::string name);
	bool graveyardContains(std::string name);
	bool gameOver();
	std::string winner();
	void kill(std::string name);
};

#endif