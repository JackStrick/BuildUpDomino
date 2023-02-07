#include "Human.h"


Human::Human()
{

}

Human::~Human()
{

}

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