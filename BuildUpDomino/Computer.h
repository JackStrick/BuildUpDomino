#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	Computer();
	~Computer();

	bool Play(Tile a_boardTile, Tile a_handtile) override;

private:
	char m_tileColor = 'W';
};

