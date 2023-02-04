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
	
	//Initializing For New Game
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
		cout << "\n\nStarting New Hand.....";
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
		while (IsPlaceableTiles(m_computer.GetHand()) || IsPlaceableTiles(m_human.GetHand()))
		{
			if (m_human.IsMyTurn())
			{
				int tile, location;
				bool play;

				//Do-While Loop That Takes In Users' Tile Placement and Validates It Or Provides Help
				do
				{
					cout << "\n\nYour Hand\n";
					m_human.ShowHand();
					m_gameBoard.DisplayGameBoard();
					cout << "\n\nEnter 99 For Help or 89 to Pass your turn";
					tile = m_msg.TileSelection();
					if (tile != 99 && tile != 89)
					{
						location = m_msg.PlacementLocation();
					}
					if (tile == 99)
					{
						cout << "\nYou need help";
						vector<vector<int>> possibleMoves;
						possibleMoves = m_human.Strategy(m_gameBoard.GetDominoStack());
						//m_msg.ShowPossibleMoves(possibleMoves);
						tile = m_msg.TileSelection();
						location = m_msg.PlacementLocation();
					}
					if (tile == 89)
					{
						if (!IsPlaceableTiles(m_human.GetHand()))
						{
							cout << "\nNo Playable Tiles So Player Can Pass";
							break;
						}
						else
						{
							cout << "\nYou have at least 1 playable tile. You may not pass your turn.";
							tile = m_msg.TileSelection();
							location = m_msg.PlacementLocation();
						}
					}
					if (!m_human.Play(m_gameBoard.GetDominoStack().at(location), m_human.GetHand().at(tile)))
					{
						play = false;
						cout << "\nThis Tile Cannot Be Placed Here\n";
					}
					else
					{
						play = true;
					}
				} while (!play);
				
				if (tile != 89)
				{
					cout << "You are ";
					m_gameBoard.TilePlacement(m_human.GetHand().at(tile), location);
					m_human.RemoveTileFromHand(tile);
				}

				SwitchTurn();
			}
			else if (m_computer.IsMyTurn())
			{
				int tile, location;
				cout << "\n\nComputer's Hand\n";
				m_computer.ShowHand();
				vector<vector<int>> possibleMoves(2);
				possibleMoves = m_computer.Strategy(m_gameBoard.GetDominoStack());
				if (possibleMoves[0].size() > 0)
				{
					do
					{
						int selection = rand() % possibleMoves.at(1).size();
						location = possibleMoves[0].at(selection);
						tile = possibleMoves[1].at(selection);

					} while (!m_computer.Play(m_gameBoard.GetDominoStack().at(location), m_computer.GetHand().at(tile)));
					cout << "\nThe computer is ";
					m_gameBoard.TilePlacement(m_computer.GetHand().at(tile), location);
					m_computer.RemoveTileFromHand(tile);
				}
				else
				{
					cout << "\nComputer Can't Place a Tile";
				}
				SwitchTurn();
			}
		}
		
		cout << "\nHand Complete!\nUpdating Scoreboard....";
		UpdatePoints();
		handCount++;	
	}

	m_gameBoard.ClearBoard();

	
}

int Round::TileCompare(Tile a_human, Tile a_computer)
{
	// If Human tile is larger than computer tile, return 1
	if (a_human.getTotalPips() > a_computer.getTotalPips())
	{
		SetPlayerTurn(m_human);
		m_computer.EndTurn();
		return 1;
	}
	// Computer tile is larger, return 2
	else if (a_human.getTotalPips() < a_computer.getTotalPips())
	{
		SetPlayerTurn(m_computer);
		m_human.EndTurn();
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

bool Round::IsPlaceableTiles(vector<Tile> &a_playerTiles)
{
	vector<Tile> board = m_gameBoard.GetDominoStack();

	//Check first players tiles
	for (int i = 0; i < board.size(); i++)
	{
		for (int i = 0; i < a_playerTiles.size(); i++)
		{
			//Tile total pips larger than on board
			if (a_playerTiles.at(i).getTotalPips() >= board.at(i).getTotalPips())
			{
				return true;
			}
			//If a double tile, it can be placed anywhere unless the stack is a double tile greater to the one in hand
			else if (a_playerTiles.at(i).getLeftPips() == a_playerTiles.at(i).getRightPips())
			{
				if (board.at(i).getLeftPips() != board.at(i).getRightPips())
				{
					return true;
				}
				else if ((board.at(i).getLeftPips() == board.at(i).getRightPips()) && (a_playerTiles.at(i).getTotalPips() > board.at(i).getTotalPips()))
				{
					return true;
				}
			}
		}
	}

	return false;
}

void Round::UpdatePoints()
{
	vector<Tile> board = m_gameBoard.GetDominoStack();
	for (int i = 0; i < board.size(); i++)
	{
		if (board.at(i).getColor() == 'W')
		{
			m_computer.SetPoints(board.at(i).getTotalPips());
		}
		else if (board.at(i).getColor() == 'B')
		{
			m_human.SetPoints(board.at(i).getTotalPips());
		}
	}

	//If Tiles in Hand - Decrease Points And Removes Tiles From Hand
	m_human.DropPoints();
	m_computer.DropPoints();
	
	m_msg.DisplayScore(GetHumanPoints(), GetComputerPoints());
}

unsigned short const Round::GetHumanPoints()
{
	return m_human.GetPoints();
}

unsigned short const Round::GetComputerPoints()
{
	return m_computer.GetPoints();
}

void Round::ResetPoints()
{
	m_human.PointReset();
	m_computer.PointReset();
}