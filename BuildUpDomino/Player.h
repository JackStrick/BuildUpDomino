//
// Player Class
//
#pragma once


#include "Tile.h"
#include "stdafx.h"

class Player
{
public:
	Player();
	~Player();



	void Play();

	void Take(vector<Tile> a_tiles);

	vector<Tile> Draw();

	void DisplayTiles();

	void Strategy() { }

	// Selectors
	unsigned int GetPoints() {};


private:
	// Data Members
	unsigned int m_points;
	vector<Tile> m_playerTiles;

};

