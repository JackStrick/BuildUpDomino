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

	void const DisplayTiles();

	void AddToHand(vector<Tile> a_playerTiles);

	void const GetHand();

	int const FirstTilePipTotal();

	void IsTurn();

	bool MyTurn();

	void PlacementOptions();

	void Strategy() {}

	// Selectors
	unsigned int GetPoints() {};


private:
	// Private Objects
	Hand m_hand;


	// Data Members
	unsigned int m_points;
	bool m_myTurn;
	vector<Tile> m_boneYard;
	vector<Tile> m_currentHand;

};

