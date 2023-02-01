#include "Computer.h"

Computer::Computer()
{

}

Computer::~Computer()
{

}

bool Computer::Play(Tile a_boardTile, Tile a_handtile)
{
	cout << "\n\nComputer's hand: \n";
	GetHand();
	Strategy();
	
	return true;
}