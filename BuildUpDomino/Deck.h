//
//
//
// References: 
// https://www.geeksforgeeks.org/creating-a-vector-of-class-objects-in-cpp/
// https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector

#pragma once
#include "stdafx.h"
#include "Tile.h"

class Deck
{
public:
	// Default Constructor
	Deck();

	// Destructor
	~Deck();

	// Selector
	vector<Tile> const Deal(unsigned short a_type);

	// Mutator 
	void GenerateTiles();

	// Utility Function
	void ShuffleDeck(vector<Tile>& a_tileVector);


private:
	// Data Members
	// Vector of white tiles - computer
	vector<Tile> m_whiteTiles;

	// Vector of black tiles - human
	vector<Tile> m_blackTiles;

	// Used to determine the caller of deal - Provides the correct color
	unsigned short m_humanType = 1;
	unsigned short m_cpuType = 2;
};

