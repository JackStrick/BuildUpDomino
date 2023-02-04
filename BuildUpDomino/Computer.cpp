#include "Computer.h"

Computer::Computer()
{

}

Computer::~Computer()
{

}

bool Computer::Play(Tile a_boardTile, Tile a_handtile)
{
	return IsValidPlacement(a_boardTile, a_handtile);
}