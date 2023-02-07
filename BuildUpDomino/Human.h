#pragma once
#include "Player.h"
#include "MessageOutput.h"

class Human : public Player
{
public:
	Human();
	~Human();

	vector<int> Choice(vector<Tile> a_gameBoardStack);


private:
	char m_tileColor = 'B';

	MessageOutput m_msg;
};

