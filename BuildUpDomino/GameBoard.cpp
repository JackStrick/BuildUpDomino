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

vector<Tile> const GameBoard::GetDominoStack()
{
	return m_Stack;
}

void const GameBoard::DisplayGameBoard()
{
	cout << "\n\n\t\t\tGAMEBOARD";
	cout << "\n\t";
	for (int i = 0; i < 6; i++)
	{
		cout << i << "\t";			
	}
	cout << "\n";
	for (int i = 0; i < m_Stack.size(); i++)
	{
		
		if (i == 6)
		{
			cout << "\n";
		}
		cout << "\t{" << m_Stack.at(i).getColor();
		cout << m_Stack.at(i).getLeftPips();
		cout << m_Stack.at(i).getRightPips() << "} ";
	}
	cout << "\n\t";
	for (int i = 6; i < 12; i++)
	{
		cout << i << "\t";
	}
}

void GameBoard::TilePlacement(Tile a_tile, int a_pos)
{
	m_Stack.at(a_pos) = a_tile;
}
