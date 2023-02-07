#pragma once
#include "Tile.h"
#include "stdafx.h"

class GameBoard
{
public:

	// Default Contstructor
	GameBoard();

	// Destructor
	~GameBoard();

	// Selectors
	vector<Tile> const GetDominoStack();
	void const DisplayGameBoard();

	// Mutators
	void SetGameBoard(vector<Tile> tiles);
	void TilePlacement(Tile a_tile, int a_pos);
	void ClearBoard();

private:
	// Data Members
	// Stack to store entire gameboard
	vector<Tile> m_Stack;
};

