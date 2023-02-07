#pragma once
#include "Tile.h"
#include "stdafx.h"

class Hand
{
public:

	// Default Constructor
	Hand();
	// Destructor
	~Hand();

	// Selector
	Tile GetInitialTile();
	int const InitialTilePipTotal();
	vector<Tile>& GetCurrentHand();
	
	// Mutator
	void InitialTile(Tile a_tile);
	void SetHand(vector<Tile>& a_playerTiles);
	void ClearHand();
	void Remove(unsigned int a_loc);

	// Utility Function
	void const DisplayHand();

private:
	// Data Member
	// Player Objects Personal Hand
	vector<Tile> m_playerHand;
};

