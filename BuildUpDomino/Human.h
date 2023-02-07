#pragma once
#include "Player.h"
#include "MessageOutput.h"

class Human : public Player
{
public:
	// Default Constructor
	Human();
	// Destructor
	~Human();

	// Utility Function
	vector<int> Choice(vector<Tile> a_gameBoardStack);

private:
	// Message Class Object
	MessageOutput m_msg;

	// Data Member Color
	char m_tileColor = 'B';
};

