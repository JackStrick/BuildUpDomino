#include "Computer.h"

Computer::Computer()
{

}

Computer::~Computer()
{

}

vector<int> Computer::Choice(vector<Tile> a_gameBoardStack)
{
	int tile, location;
	vector<int> tile_loc;
	cout << "\n\nComputer's Hand\n";
	ShowHand();
	vector<vector<int>> possibleMoves(2);
	possibleMoves = Strategy(a_gameBoardStack);
	if (possibleMoves[0].size() > 0)
	{
		do
		{
			int selection = rand() % possibleMoves.at(1).size();
			location = possibleMoves[0].at(selection);
			tile = possibleMoves[1].at(selection);

		} while (!Play(a_gameBoardStack.at(location), GetHand().at(tile)));
		cout << "\nThe computer is ";
		tile_loc.push_back(tile);
		tile_loc.push_back(location);
		return tile_loc;
	}
	else
	{
		cout << "\nComputer Can't Place a Tile";
	}
}