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
			if (first == repeat)
			{
				cout << "\nTile Values The Same\nTiles added back to players boneyard\n\nPlayers Redrawing Tiles...";
				m_human.ReturnTiles();
				m_computer.ReturnTiles();
			}
		} while (first == repeat);

		m_msg.FirstUp(first, m_human.FirstTilePipTotal(), m_computer.FirstTilePipTotal());
		m_human.AddToHand(m_human.Draw(5));
		m_computer.AddToHand(m_computer.Draw(5));

		unsigned short turnCounter = 12;
		while (turnCounter > 0)
		{
			if (m_human.MyTurn())
			{
				//Tile tile = m_human.Play(m_gameBoard);
				//m_gameBoard.TilePlacement(tile, );
				m_gameBoard.DisplayGameBoard();
				SwitchTurn();
				turnCounter--;
			}
		}
		

				





		handCount++;
	}

	

}

int Round::TileCompare(Tile a_human, Tile a_computer)
{
	// If Human tile is larger than computer tile, return 1
	if (a_human.getTotalPips() > a_computer.getTotalPips())
	{
		SetTurn(m_human);
		return 1;
	}
	// Computer tile is larger, return 2
	else if (a_human.getTotalPips() < a_computer.getTotalPips())
	{
		SetTurn(m_computer);
		return 2;
	}
	// If tiles are same value then redraw initial tile
	else
	{
		return 3;
	}

}

void Round::SetTurn(Player a_player)
{
	a_player.IsTurn();
}

void Round::SwitchTurn()
{

}