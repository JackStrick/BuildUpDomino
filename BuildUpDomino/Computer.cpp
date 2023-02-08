#include "Computer.h"

Computer::Computer()
{

}

Computer::~Computer()
{

}

/* *********************************************************************
Function Name: Choice
Purpose: Virtual Function - Computer specific player function to determine
			which tile to place
Parameters: 
			a_gameBoardStack, the vector of tiles that represents
			the entire gameboard
Return Value: 
			vector<int> that contains the tile position in players 
			hand and the position on the gameboard with which to place
			the tile
Algorithm:
			1) Shows the computers hand to the user
				(For demo purposes)

			2) Calls for the Player:Strategy function to get a move
				and returns a vector of a vector of ints that holds 
				the possible move and the location in a hand of which
				tile to place

			3) If there is a move in possibleMoves, then place the move
				onto a vector of ints that will be returned 

			4) If possibleMoves is empty, the computer cannot play
				so it should not give a move

Assistance Received: none
********************************************************************* */
vector<int> Computer::Choice(vector<Tile> a_gameBoardStack)
{
	// Will hold the tile position from hand in [0]
	// Will hold the tile position on the gameboard in [1]
	vector<int> tile_loc;

	cout << "\n\nComputer's Hand\n";
	ShowHand();

	// possibleMoves will hold the gameboard position and hand position
	vector<vector<int>> possibleMoves = Strategy(a_gameBoardStack);

	// Check that possibleMoves has a move, return that move
	if (possibleMoves[0].size() > 0)
	{
		cout << "\nThe computer is ";
		tile_loc.push_back(possibleMoves[1].at(0));
		tile_loc.push_back(possibleMoves[0].at(0));
		return tile_loc;
	}
	else
	{
		cout << "\nComputer Can't Place a Tile";
	}
}