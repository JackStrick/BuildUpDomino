//
// Player Class
//
#pragma once


#include "Tile.h"
#include "Hand.h"
#include "stdafx.h"

class Player
{
public:
	Player();
	~Player();



	void Play();

	void Take(vector<Tile> a_tiles);

	vector<Tile> Draw(int a_amount);

	Tile InitialTile();

	void ReturnTiles();

	void DisplayTiles();

	void AddToHand(vector<Tile> a_playerTiles);

	void GetHand();

	int FirstTilePipTotal();

	void Strategy() { }

	// Selectors
	unsigned int GetPoints() {};


private:
	// Private Objects
	Hand m_hand;


	// Data Members
	unsigned int m_points;

	// Bone yard - All Player Tiles For Game - Black or White
	vector<Tile> m_playerTiles;

};

