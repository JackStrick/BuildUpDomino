#include "Player.h"
#include "stdafx.h"

Player::Player()
{

}

Player::~Player()
{

}

/* *********************************************************************
Function Name: GetHand
Purpose: To get the current players hand
Parameters: None
Return Value: vector<Tile> players hand
Algorithm: None
Assistance Received: none
********************************************************************* */
vector<Tile>& Player::GetHand()
{
	return m_hand.GetCurrentHand();
}

/* *********************************************************************
Function Name: GetBoneYard
Purpose: To get the current players boneyard
Parameters: None
Return Value: vector<Tile> players boneyard
Algorithm: None
Assistance Received: none
********************************************************************* */
vector<Tile> const Player::GetBoneYard()
{
	return m_boneYard;
}

/* *********************************************************************
Function Name: FirstTilePipTotal
Purpose: To get tile total of the players first tile
Parameters: None
Return Value: int of total tile pips
Algorithm: None
Assistance Received: none
********************************************************************* */
int const Player::FirstTilePipTotal()
{
	return m_hand.InitialTilePipTotal();
}

/* *********************************************************************
Function Name: IsMyTurn
Purpose: To check if its the current players turn
Parameters: None
Return Value: bool - true if players turn
Algorithm: None
Assistance Received: none
********************************************************************* */
bool const Player::IsMyTurn()
{
	return m_myTurn;
}

/* *********************************************************************
Function Name: ShowHand
Purpose: To Display the current players hand to the console
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void const Player::ShowHand()
{
	m_hand.DisplayHand();
}

/* *********************************************************************
Function Name: Play
Purpose: To check if the tile can be played
Parameters: 
			a_boardTile, 
			a_handtile, 
Return Value: bool - True when tile choice and location choice
						are allowed to be placed
Algorithm: None
Assistance Received: none
********************************************************************* */
bool const Player::Play(Tile a_boardTile, Tile a_handtile)
{
	return IsValidPlacement(a_boardTile, a_handtile);
}

/* *********************************************************************
Function Name: GetPoints
Purpose: To get the players points
Parameters: None
Return Value: Players Points
Algorithm: None
Assistance Received: none
********************************************************************* */
unsigned short const Player::GetPoints()
{
	return m_points;
}

/* *********************************************************************
Function Name: GetRoundsWin
Purpose: To get the players rounds won
Parameters: None
Return Value: Players rounds won count
Algorithm: None
Assistance Received: none
********************************************************************* */
unsigned short const Player::GetRoundsWon()
{
	return m_roundsWon;
}

/* *********************************************************************
Function Name: DisplayBoneyard
Purpose: To display the players boneyard to console
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void const Player::DisplayBoneyard()
{
	for (int i = 0; i < m_boneYard.size(); i++)
	{
		cout << "{" << m_boneYard.at(i).getColor();
		cout << m_boneYard.at(i).getLeftPips();
		cout << m_boneYard.at(i).getRightPips() << "} ";
	}
}


//MUTATOR START
/* *********************************************************************
Function Name: Take
Purpose: To take tiles from the deck
Parameters:
			a_tiles, vector of tile objects
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::Take(vector<Tile> a_tiles)
{
	m_boneYard = a_tiles;
}

/* *********************************************************************
Function Name: Draw
Purpose: To gather tiles from player boneyard into hand
Parameters: None
Return Value: 
				playerHand, a vector of Tile objects representing the 
				tiles in the players hand
Algorithm: 
			1) Checks the size of the boneyard to indicate how far
				players are into the game
				a) This gets used to create the gameboard and
					also every hand after
				b) The last hand only draws 4 tiles 
Assistance Received: none
********************************************************************* */
vector<Tile> Player::Draw()
{
	vector<Tile> playerHand;
	// 6 Tiles for creating gameboard
	if (m_boneYard.size() == 28)
	{
		for (int i = 0; i < 6; i++)
		{
			int selection = rand() % m_boneYard.size();
			playerHand.push_back(m_boneYard.at(selection));
			m_boneYard.erase(m_boneYard.begin() + selection);
		}
	}
	// 5 Tiles while not last hand 
	else if (m_boneYard.size() > 4)
	{
		for (int i = 0; i < 5; i++)
		{
			int selection = rand() % m_boneYard.size();
			playerHand.push_back(m_boneYard.at(selection));
			m_boneYard.erase(m_boneYard.begin() + selection);
		}
	}
	// 4 Tiles for last hand
	else
	{
		for (int i = 0; i < 3; i++)
		{
			int selection = rand() % m_boneYard.size();
			playerHand.push_back(m_boneYard.at(selection));
			m_boneYard.erase(m_boneYard.begin() + selection);
		}
	}
	return playerHand;
}


/* *********************************************************************
Function Name: SetStacks
Purpose: To set the gameboard stacks by parsing a stack string
			This is used when starting from a file 
Parameters: string stack, string containing stack info
Return Value:
				stackTiles, a vector of Tile objects representing the
				tiles that make up the gameboard
Algorithm: None
Assistance Received: none
********************************************************************* */
vector<Tile> Player::SetStacks(string a_stack)
{
	char color;
	int left;
	int right;
	vector<Tile> stackTiles;
	for (int i = 0; a_stack[i] != '\0'; i++)
	{
		if (a_stack[i] != ' ')
		{
			if (a_stack[i] == 'W' || a_stack[i] == 'B')
			{
				// Add each tile object to the gameboard stacks
				Tile tile(a_stack[i], a_stack[i + 1] - 48, a_stack[i + 2] - 48);
				stackTiles.push_back(tile);
			}
		}
	}
	return stackTiles;
}

/* *********************************************************************
Function Name: SetBoneyard
Purpose: To set the boneyard by parsing a boneyard string
			This is used when starting from a file
Parameters: string a_boneyard, string containing boneyard info
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::SetBoneyard(string a_boneyard)
{
	char color;
	int left;
	int right;
	
	// Loop through the string from start to finish
	for (int i = 0; a_boneyard[i] != '\0'; i++)
	{
		if (a_boneyard[i] != ' ')
		{
			if (a_boneyard[i] == 'W' || a_boneyard[i] == 'B')
			{
				// Create each tile object and add them to the boneyard
				Tile tile(a_boneyard[i], a_boneyard[i + 1] - 48, a_boneyard[i + 2] - 48);
				m_boneYard.push_back(tile);
			}
		}
	}
}

/* *********************************************************************
Function Name: SetHand
Purpose: To set the players hand by parsing a hand string
			This is used when starting from a file
Parameters: string a_hand, string containing hand info
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::SetHand(string a_hand)
{
	vector<Tile> handTiles;
	for (int i = 0; a_hand[i] != '\0'; i++)
	{
		if (a_hand[i] != ' ')
		{
			if (a_hand[i] == 'W' || a_hand[i] == 'B')
			{
				// Add each tile object to the player hand
				Tile tile(a_hand[i], a_hand[i + 1] - 48, a_hand[i + 2] - 48);
				handTiles.push_back(tile);
			}
		}
	}
	// Adds the tiles to the players hand
	AddToHand(handTiles);
}

/* *********************************************************************
Function Name: PointReset
Purpose:
		Drop Player points back to 0
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::PointReset()
{
	m_points = 0;
}

/* *********************************************************************
Function Name: SetPoint
Purpose: 
		Add points to the running total
Parameters: 
			a_points, holding the players current points after
			a hand
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::SetPoints(unsigned int a_points)
{
	m_points += a_points;
}


/* *********************************************************************
Function Name: SetRoundsWon
Purpose: To set the number of rounds a player has won
			This is used when starting from a file
Parameters: 
			a_rounds, unsugned short of total rounds a player
			has won so far
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::SetRoundsWon(unsigned short a_rounds)
{
	m_roundsWon = a_rounds;
}

/* *********************************************************************
Function Name: SetTurn
Purpose:
		Sets the players turn to true
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::SetTurn()
{
	m_myTurn = true;
}

/* *********************************************************************
Function Name: EndTurn
Purpose:
		Sets the players turn to false
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::EndTurn()
{
	m_myTurn = false;
}


/* *********************************************************************
Function Name: ReturnTiles
Purpose:
		Returns initial tile back to the boneyard, clears the hand,
		and reshuffles the boneyard
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::ReturnTiles()
{
	Tile playerTile = m_hand.GetInitialTile();
	m_hand.ClearHand();
	m_boneYard.push_back(playerTile);
	ShuffleBoneyard();
}

/* *********************************************************************
Function Name: AddHand
Purpose:
		Sets the players hand to be equal to the vector of
		tile objects being passed in
Parameters: 
			a_playerTiles, vector of tile objects
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::AddToHand(vector<Tile> a_playerTiles)
{
	m_hand.SetHand(a_playerTiles);
}

/* *********************************************************************
Function Name: RemoveTileFromHand
Purpose:
		Removes the tile at the index given by a_loc
Parameters: a_loc, the index of which tile to removed from
			the hand
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::RemoveTileFromHand(unsigned int a_loc)
{
	m_hand.Remove(a_loc);
}


/* *********************************************************************
Function Name: DropPoints
Purpose:
		Decreases the players points based on the tiles remaining 
		in their hand once the hand ends, and then removes them
		from the hand
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::DropPoints()
{
	if (!GetHand().empty())
	{
		int handSize = GetHand().size();
		for (int i = 0; i < handSize; i++)
		{
			int pips = GetHand().at(0).getTotalPips();
			if ((m_points - pips) < 0)
			{
				m_points = 0;
			}
			else
			{
				m_points -= pips;
			}
			RemoveTileFromHand(0);
		}
	}
}


/* *********************************************************************
Function Name: WonRound
Purpose:
		Called when a player wins the round. Increase their win
		count by 1
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::WonRound()
{
	m_roundsWon += 1;
}

//UTILITY FUNCTIONS
/* *********************************************************************
Function Name: ShuffleBoneyard
Purpose:
		Used to shuffle a players boneyard after they put a
		tile back in their pile
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: none
********************************************************************* */
void Player::ShuffleBoneyard()
{
	srand(time(0));
	random_shuffle(m_boneYard.begin(), m_boneYard.end());
}

/* *********************************************************************
Function Name: InitialTile
Purpose:
		Randomly selects a tile from the shuffled boneyard and
		returns it to a players hand to check who will go first
Parameters: None
Return Value: 
			playerTile, the tile object that will determine who
			goes first
Algorithm: None
Assistance Received: none
********************************************************************* */
Tile Player::InitialTile()
{

	int selection = rand() % m_boneYard.size();

	Tile playerTile = m_boneYard.at(selection);

	m_boneYard.erase(m_boneYard.begin() + selection);

	m_hand.InitialTile(playerTile);

	return playerTile;
}




/* *********************************************************************
Function Name: Strategy
Purpose:
		The logic used by the computer to play a peice. Computer uses
		for each play. Human can ask for help.
Parameters: 
			a_gameboard, a vector of tile objects representing
			the gameboard stacks
Return Value:
			possibleMoves, a vector of a vector of integers
			possibleMoves[0] = the location on the gameboard
			possibleMoves[1] = the tile position in player hand
Algorithm: 
			1) First check if the player has B or W tiles in hand
				a) The player with B tiles will prefer to place on
					top of white tiles
				b) The player with W tiles will prefer to place on
					top of black tiles
			2) The strategy:
					a) Loop through all of the stacks with
						every tile in hand.
					b) Verify if each is valid to place
					c) If a tile is valid and possibleMoves is empty,
						add the tile location and stack location
					d) Every valid tile after, check which is the 
						lowest possible tile that can be placed on the
						highest possible stack of opposing teams tiles
					e) If there are no options to place on top of the
						opposing players stacks	place on the best of your own

Assistance Received: 
	https://linuxhint.com/append-vector-cpp/#:~:text=Appending%20to%20a%20vector%20means,to%20append%20is%20push_back().
********************************************************************* */
vector<vector<int>> Player::Strategy(vector<Tile> a_gameboard)
{
	vector<vector<int>> possibleMoves(2);
	// Check which player is going
	if (GetHand().at(0).getColor() == 'B')
	{
		// First the player will attempt to play a tile on top of the opposing players tile
		for (int location = 0; location < a_gameboard.size(); location++)
		{
			for (int tile = 0; tile < GetHand().size(); tile++)
			{
				if (a_gameboard.at(location).getColor() == 'W')
				{
					if (IsValidPlacement(a_gameboard.at(location), GetHand().at(tile)))
					{
						// Add the first valid placement, this will be default and checked against every time after
						if (possibleMoves[0].empty())
						{
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
						// If there is a better position, lower tile from hand and higher tile on stack,
						// Remove possible move and add the new one
						else if (a_gameboard.at(location).getTotalPips() >= a_gameboard.at(possibleMoves[0].at(0)).getTotalPips() && GetHand().at(tile).getTotalPips() < GetHand().at(possibleMoves[1].at(0)).getTotalPips())
						{
							possibleMoves[0].clear();
							possibleMoves[1].clear();
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
					}
				}

			}
		}
		// This is empty if there is no location to place on top of your opponents tile
		if (possibleMoves[0].empty())
		{
			// Now will check the rest of the board for any possible moves
			cout << "\nSince there are no moves to play on White Tiles";
			for (int location = 0; location < a_gameboard.size(); location++)
			{
				for (int tile = 0; tile < GetHand().size(); tile++)
				{
					if (IsValidPlacement(a_gameboard.at(location), GetHand().at(tile)))
					{
						if (possibleMoves[0].empty())
						{
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
						else if (a_gameboard.at(location).getTotalPips() >= a_gameboard.at(possibleMoves[0].at(0)).getTotalPips() && GetHand().at(tile).getTotalPips() < GetHand().at(possibleMoves[1].at(0)).getTotalPips())
						{
							possibleMoves[0].clear();
							possibleMoves[1].clear();
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
					}
				}
			}
			// Based on the gameboard position of the vector
			// Determine the stack name
			string stack;
			if (possibleMoves[0].at(0) < 6)
			{
				stack = "B" + (possibleMoves[0].at(0) + 1);
			}
			else if (possibleMoves[0].at(0) > 5)
			{
				stack = "W" + (possibleMoves[0].at(0) - 5);
			}

			cout << "\nThe best move is to play Tile {" << GetHand().at(possibleMoves[1].at(0)).getColor() << GetHand().at(possibleMoves[1].at(0)).getLeftPips() << GetHand().at(possibleMoves[1].at(0)).getRightPips() << "} ";
			cout << "on stack " << stack << " \nSince that is the lowest tile and highest stack tile";
		}
		else {
			string stack;
			if (possibleMoves[0].at(0) < 6)
			{
				stack = "B" + to_string(possibleMoves[0].at(0) + 1);
			}
			else if (possibleMoves[0].at(0) > 5)
			{
				stack = "W" + to_string(possibleMoves[0].at(0) - 5);
			}
			cout << "\nA tile can be played on top of a white tile";
			cout << "\nThe best move is to play Tile {" << GetHand().at(possibleMoves[1].at(0)).getColor() << GetHand().at(possibleMoves[1].at(0)).getLeftPips() << GetHand().at(possibleMoves[1].at(0)).getRightPips() << "} ";
			cout << "on Stack " << stack << " \nSince that is the lowest tile that can play on top of this stack tile";
		}

	}

	else if (GetHand().at(0).getColor() == 'W')
	{
		// First the player will attempt to play a tile on top of the opposing players tile
		for (int location = 0; location < a_gameboard.size(); location++)
		{
			for (int tile = 0; tile < GetHand().size(); tile++)
			{
				if (a_gameboard.at(location).getColor() == 'B')
				{
					if (IsValidPlacement(a_gameboard.at(location), GetHand().at(tile)))
					{
						// Add the first valid placement, this will be default and checked against every time after
						if (possibleMoves[0].empty())
						{
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
						// If there is a better position, lower tile from hand and higher tile on stack,
						// Remove possible move and add the new one
						else if (a_gameboard.at(location).getTotalPips() >= a_gameboard.at(possibleMoves[0].at(0)).getTotalPips() && GetHand().at(tile).getTotalPips() < GetHand().at(possibleMoves[1].at(0)).getTotalPips())
						{
							possibleMoves[0].clear();
							possibleMoves[1].clear();
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
					}
				}

			}
		}
		// This is empty if there is no location to place on top of your opponents tile
		if (possibleMoves[0].empty())
		{
			cout << "\nSince there are no moves to play on Black Tiles";
			for (int location = 0; location < a_gameboard.size(); location++)
			{
				// Now will check the rest of the board for any possible moves
				for (int tile = 0; tile < GetHand().size(); tile++)
				{
					if (IsValidPlacement(a_gameboard.at(location), GetHand().at(tile)))
					{
						if (possibleMoves[0].empty())
						{
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
						else if (a_gameboard.at(location).getTotalPips() >= a_gameboard.at(possibleMoves[0].at(0)).getTotalPips() && GetHand().at(tile).getTotalPips() < GetHand().at(possibleMoves[1].at(0)).getTotalPips())
						{
							possibleMoves[0].clear();
							possibleMoves[1].clear();
							possibleMoves[0].push_back(location);
							possibleMoves[1].push_back(tile);
						}
					}
				}
			}
		}
		else {
			cout << "\nThe computer has a tile that can be placed on top of a human's tile";
			cout << "\nThe computer will choose the lowest tile that can be placed on the highest stack tile";
		}
	}

	return possibleMoves;
}

/* *********************************************************************
Function Name: IsValidPlacement
Purpose:
		Checks if the players choice of tile is a valid
		move
Parameters:
			Tile a_boardTile, the tile on the gamboard
			Tile a_handtile, the tile from the players hand
Return Value:
			bool -> True - If move is valid
			bool -> False - If move is not valid
Algorithm: None
Assistance Received:
	https://www.tutorialspoint.com/how-to-print-out-the-contents-of-a-vector-in-cplusplus
********************************************************************* */
bool Player::IsValidPlacement(Tile a_boardTile, Tile a_handtile)
{
	// If hand tile is larger than board, always true
	if (a_handtile.getTotalPips() >= a_boardTile.getTotalPips())
	{
		return true;
	}
	// If the hand tile is a double tile
	else if (a_handtile.getLeftPips() == a_handtile.getRightPips())
	{
		// Check if the board tile is a double tile, if not always return true
		if ((a_boardTile.getLeftPips() != a_boardTile.getRightPips()))
		{
			return true;
		}
		// If board tile is a double, make sure the hand tile is larger
		else if ((a_boardTile.getLeftPips() == a_boardTile.getRightPips()) && (a_handtile.getTotalPips() > a_boardTile.getTotalPips()))
		{
			return true;
		}
	}
	return false;
}

/* *********************************************************************
Function Name: IsValidPlaceableTile
Purpose:
		Checks if either player has any tiles in their hand that are
		valid moves
Parameters:
			a_gameBoardTiles, the tiles on the gamboard
			a_playerTiles, the tiles from the players hand
Return Value:
			bool -> True - If there exists a tile in hand that can be played
			bool -> False - If there is no tile in hand that can be played
Algorithm: None
Assistance Received: None
********************************************************************* */
bool Player::IsValidPlaceableTile(vector<Tile>& a_playerTiles, vector<Tile>& a_gameBoardTiles)
{

	//Check first players tiles
	for (int i = 0; i < a_gameBoardTiles.size(); i++)
	{
		for (int i = 0; i < a_playerTiles.size(); i++)
		{
			//Tile total pips larger than on board
			if (a_playerTiles.at(i).getTotalPips() >= a_gameBoardTiles.at(i).getTotalPips())
			{
				return true;
			}
			//If a double tile, it can be placed anywhere unless the stack is a double tile greater to the one in hand
			else if (a_playerTiles.at(i).getLeftPips() == a_playerTiles.at(i).getRightPips())
			{
				if (a_gameBoardTiles.at(i).getLeftPips() != a_gameBoardTiles.at(i).getRightPips())
				{
					return true;
				}
				else if ((a_gameBoardTiles.at(i).getLeftPips() == a_gameBoardTiles.at(i).getRightPips()) && (a_playerTiles.at(i).getTotalPips() > a_gameBoardTiles.at(i).getTotalPips()))
				{
					return true;
				}
			}
		}
	}
	return false;
}