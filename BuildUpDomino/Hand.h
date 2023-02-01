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

	int const InitialTilePipTotal();

	void const DisplayHand();

	vector<Tile>& GetCurrentHand();

	void SetHand(vector<Tile> &a_playerTiles);

	Tile GetInitialTile();

	void Remove(unsigned int a_loc);





private:
	vector<Tile> m_playerHand;

};

