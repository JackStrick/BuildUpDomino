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



	virtual bool Play(Tile a_boardTile, Tile a_handtile) = 0;

	void Take(vector<Tile> a_tiles);

	vector<Tile> Draw();

	Tile InitialTile();

	void ReturnTiles();

	void const DisplayBoneyard();

	void AddToHand(vector<Tile> a_playerTiles);

	vector<Tile>& GetHand();

	void RemoveTileFromHand(unsigned int a_loc);

	void const ShowHand();

	int const FirstTilePipTotal();

	void SetTurn();

	bool IsMyTurn();

	void EndTurn();

	bool IsValidPlacement(Tile a_boardTile, Tile a_handtile);

	void Strategy() {};

	// Selectors
	unsigned int GetPoints() {};

	void SetPoints(unsigned int a_points);


private:
	// Private Objects
	Hand m_hand;


	// Data Members
	unsigned int m_points;
	bool m_myTurn;
	vector<Tile> m_boneYard;
	vector<Tile> m_currentHand;

};

