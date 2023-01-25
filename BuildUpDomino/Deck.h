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

	Deck();
	~Deck();

	// Selectors
	int TilesRemaining(vector<Tile>& a_tileVector) {};
	void ShuffleDeck(vector<Tile> &a_tileVector);
	vector<Tile> Deal(unsigned short a_type);


	// Generators
	void GenerateTiles();




private:
	vector<Tile> m_whiteTiles;
	vector<Tile> m_blackTiles;

	unsigned short m_humanType = 1;
	unsigned short m_cpuType = 2;

};

