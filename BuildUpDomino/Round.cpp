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
	m_gameBoard.SetGameBoard(m_human.Draw());

	// Computer draws 6 and places them on the gameboard
	m_gameBoard.SetGameBoard(m_computer.Draw());

	m_gameBoard.DisplayGameBoard();

	
	while (handCount < 4)
	{
		int repeat = 3;
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
		m_human.AddToHand(m_human.Draw());
		m_computer.AddToHand(m_computer.Draw());

		while (IsPlaceableTiles(m_computer.GetHand(), m_human.GetHand()))
		{
			if (m_human.IsMyTurn())
			{
				int tile, location;

				//Do-While Loop That Takes In Users' Tile Placement and Validates It Or Provides Help
				do
				{
					m_human.ShowHand();
					m_gameBoard.DisplayGameBoard();
					tile = m_msg.TileSelection();
					if (tile == 99)
					{
						cout << "\nYou need help";
						m_human.Strategy();
						tile = m_msg.TileSelection();
					}
					location = m_msg.PlacementLocation();
				
					
				} while (!m_human.Play(m_gameBoard.GetDominoStack().at(location), m_human.GetHand().at(tile)));
				
				m_gameBoard.TilePlacement(m_human.GetHand().at(tile), location);
				m_human.RemoveTileFromHand(tile);

				SwitchTurn();
			}
			else if (m_computer.IsMyTurn())
			{
				//m_computer.Play();
				m_gameBoard.DisplayGameBoard();
				SwitchTurn();
			}
		}
		
		/// <summary>
		/// UpdatePoints();
		/// ADD ALL TILES WITH WHITE TO PLAYER
		/// ADD ALL TILES ON TOP WITH BLACK TO PLAYER
		/// IF PLAYER HAS TILES IN HAND SUBTRACT POINTS - POINTS SHOULDN'T GO BELOW ZERO
		/// </summary>
		
		handCount++;
		
	}

	

}

int Round::TileCompare(Tile a_human, Tile a_computer)
{
	// If Human tile is larger than computer tile, return 1
	if (a_human.getTotalPips() > a_computer.getTotalPips())
	{
		SetPlayerTurn(m_human);
		return 1;
	}
	// Computer tile is larger, return 2
	else if (a_human.getTotalPips() < a_computer.getTotalPips())
	{
		SetPlayerTurn(m_computer);
		return 2;
	}
	// If tiles are same value then redraw initial tile
	else
	{
		return 3;
	}

}

void Round::SetPlayerTurn(Player &a_player)
{
	a_player.SetTurn();
}

void Round::SwitchTurn()
{
	if (m_computer.IsMyTurn())
	{
		SetPlayerTurn(m_human);
		m_computer.EndTurn();
	}
	else if (m_human.IsMyTurn())
	{
		SetPlayerTurn(m_computer);
		m_human.EndTurn();
	}
}

bool Round::IsPlaceableTiles(vector<Tile> &a_player1Tiles, vector<Tile> &a_player2Tiles)
{
	vector<Tile> board = m_gameBoard.GetDominoStack();
	vector<Tile> playerTilesInHand = a_player1Tiles;
	playerTilesInHand.insert(playerTilesInHand.begin(), a_player2Tiles.begin(), a_player2Tiles.end());

	//Check first players tiles
	for (int i = 0; i < board.size(); i++)
	{
		for (int i = 0; i < playerTilesInHand.size(); i++)
		{
			//Tile total pips larger than on board
			if (playerTilesInHand.at(i).getTotalPips() >= board.at(i).getTotalPips())
			{
				return true;
			}
			//If a double tile, it can be placed anywhere unless the stack is a double tile greater to the one in hand
			else if (playerTilesInHand.at(i).getLeftPips() == playerTilesInHand.at(i).getRightPips())
			{
				if ((board.at(i).getLeftPips() == board.at(i).getRightPips()) && (playerTilesInHand.at(i).getTotalPips() > board.at(i).getTotalPips()))
				{
					return true;
				}
			}
		}
	}

	return false;
	
}