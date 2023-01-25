#include "GameBoard.h"



GameBoard::GameBoard()
{

}// Initialize with Player and Computer First 6?


GameBoard::~GameBoard()
{

}

void GameBoard::SetGameBoard(vector<Tile> a_tiles)
{
	for (int i = 0; i < a_tiles.size(); i++)
	{
		m_Stack.push_back(a_tiles.at(i));
	}
}

vector<Tile> GameBoard::GetDominoStack()
{
	return m_Stack;
}
