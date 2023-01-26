#pragma once
#include "Tile.h"
#include "stdafx.h"

class Hand
{
public:
	Hand();
	~Hand();


	void InitialTile(Tile a_tile);

	void ClearHand();

	int InitialTilePipTotal();

	void SetHand(vector<Tile> a_playerTiles);

	Tile GetInitialTile();





private:
	vector<Tile> m_playerHand;

};

