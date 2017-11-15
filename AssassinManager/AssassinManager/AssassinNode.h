//	AssassinNode.h
//		This file defines the public interface for the AssassinNode class

#ifndef ASSASSINNODE_H
#define ASSASSINNODE_H

#include <string>

class AssassinNode {

public:
	std::string name;
	std::string killer;
	AssassinNode* next;

	AssassinNode(std::string name);
	AssassinNode(std::string name, AssassinNode* next);
};

#endif