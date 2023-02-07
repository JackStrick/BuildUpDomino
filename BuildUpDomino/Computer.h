#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	Computer();
	~Computer();

	vector<int> Choice(vector<Tile> a_gameBoardStack);

private:
	char m_tileColor = 'W';
};

