#pragma once
#include "Tile.h"
#include "stdafx.h"

class GameBoard
{
public:
	GameBoard();
	~GameBoard();


	void SetGameBoard(vector<Tile> tiles);

	void TilePlacement(Tile a_tile, int a_pos);

	void const DisplayGameBoard();

	void ClearBoard();

	vector<Tile> const GetDominoStack();


private:
	//Tile m_dominoStack[12];
	vector<Tile> m_Stack;
	static unsigned short count;

};

