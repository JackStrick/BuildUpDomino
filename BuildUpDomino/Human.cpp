#include "Human.h"


Human::Human()
{

}

Human::~Human()
{

}

/* *********************************************************************
Function Name: Choice
Purpose: Virtual Function - Human specific player function to determine
			which tile the user would like to place, or to get help
			from the computer
Parameters:
			a_gameBoardStack, the vector of tiles that represents
			the entire gameboard
Return Value:
			vector<int> that contains the tile position in players
			hand and the position on the gameboard with which to place
			the tile
Algorithm:
			1) Shows humans hand to the user

			2) Asks the user for the tile and stack location
				they want to put the tile onto
					a) If that is not a valid move, repeat
					b) If valid move continue

			3) If the user asks for help, call strategy to get the best
				move for the user to make
					a) If one exists, then display it to the user
					b) ask again for a user to enter a tile and location

			4) If the user asks to pass, make sure they have no playable
				tiles, and either alert them that they have a possible move
				or allow the user to pass

			5) This entire function is wrapped in a do-while loop that will
				only break after the user gives a valid tile or if the user
				was allowed to pass
			

Assistance Received: None
********************************************************************* */
vector<int> Human::Choice(vector<Tile> a_gameBoardStack)
{
	vector<int> tile_loc;
	int tile, location;
	bool play;

	//Do-While Loop That Takes In Users' Tile Placement and Validates It Or Provides Help
	do
	{
		cout << "\n\nYour Hand\n";
		ShowHand();
		
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
			//
			//vector<int> tempTileLoc 
			// 
			possibleMoves = Strategy(a_gameBoardStack);
			//m_msg.ShowPossibleMoves(tempTileLoc);
			tile = m_msg.TileSelection();
			location = m_msg.PlacementLocation();
		}
		if (tile == 89)
		{
			if (!IsValidPlaceableTile(GetHand(), a_gameBoardStack))
			{
				cout << "\nNo Playable Tiles So Player Can Pass";
				tile_loc.clear();
				break;
			}
			else
			{
				cout << "\nYou have at least 1 playable tile. You may not pass your turn.";
				tile = m_msg.TileSelection();
				location = m_msg.PlacementLocation();
			}
		}
		if (!Play(a_gameBoardStack.at(location), GetHand().at(tile)))
		{
			play = false;
			cout << "\nThis Tile Cannot Be Placed Here\n";
		}
		else
		{
			tile_loc.push_back(tile);
			tile_loc.push_back(location);
			play = true;

		}
	} while (!play);

	return tile_loc;
}