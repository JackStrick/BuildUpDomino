#pragma once
#include "Player.h"
class Human : public Player
{
public:
	Human();
	~Human();

	bool Play(Tile a_boardTile, Tile a_handtile);


private:

};

