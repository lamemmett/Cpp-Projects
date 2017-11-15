//	AssassinNode.cpp
//		This file defines the member functions of the AssassinNode class

#include "stdafx.h"
#include "AssassinNode.h"

using namespace std;

// Constructor (1 parameter)
AssassinNode::AssassinNode(std::string name) {
	AssassinNode::name = name;
	AssassinNode::killer = "";
	AssassinNode::next = NULL;
}

// Constructor override (2 parameters)
AssassinNode::AssassinNode(std::string name, AssassinNode* next) {
	AssassinNode::name = name;
	AssassinNode::killer = "";
	AssassinNode::next = next;
}