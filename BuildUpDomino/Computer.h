#pragma once
#include "Player.h"

class Computer : public Player
{
public:

	// Default Constructor
	Computer();
	// Destructor
	~Computer();

	// Utility Function
	vector<int> Choice(vector<Tile> a_gameBoardStack);

private:
	// Data Member Color
	char m_tileColor = 'W';
};

