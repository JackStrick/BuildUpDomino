#include "Round.h"
#include "MessageOutput.h"

Round::Round()
{

}

Round::~Round()
{

}

void Round::StartRound()
{
	int handCount = 0;
	int first = 0;
	//The deck is created and shuffled for computer and human
	m_deck.GenerateTiles();

	// Human takes their 28 tiles
	m_human.Take(m_deck.Deal(m_humanType));
	// Computer takes their 28 tiles
	m_computer.Take(m_deck.Deal(m_cpuType));
	
	// Human Draws 6 and places them on the gameboard
	m_gameBoard.SetGameBoard(m_human.Draw(6));

	// Computer draws 6 and places them on the gameboard
	m_gameBoard.SetGameBoard(m_computer.Draw(6));

	m_gameBoard.DisplayGameBoard();

	int repeat = 3;
	while (handCount < 3)
	{
		do
		{
			cout << "\n\nBoth Players Drawing First Tile Of Hand";
			first = TileCompare(m_human.InitialTile(), m_computer.InitialTile());
			if (first == 3)
			{
				cout << "\nTile Values The Same\nTiles added back to players boneyard\n\nPlayers Redrawing Tiles...";
				m_human.ReturnTiles();
				m_computer.ReturnTiles();
			}
		} while (first == repeat);

		m_msg.FirstUp(first, m_human.FirstTilePipTotal(), m_computer.FirstTilePipTotal());
		m_human.AddToHand(m_human.Draw(5));
		m_computer.AddToHand(m_computer.Draw(5));

		cout << "\n\nYour Current Hand\n";
		m_human.GetHand();

		

				





		handCount++;
	}

	

}

int Round::TileCompare(Tile a_human, Tile a_computer)
{
	// If Human tile is larger than computer tile, return true
	if (a_human.getTotalPips() > a_computer.getTotalPips())
	{
		return 1;
	}
	// Computer tile is larger, return false
	else if (a_human.getTotalPips() < a_computer.getTotalPips())
	{
		return 2;
	}
	// If tiles are same value then redraw initial tile
	else
	{
		return 3;
	}

}