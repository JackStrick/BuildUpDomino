#include "Human.h"

Human::Human()
{

}

Human::~Human()
{

}

bool Human::Play(Tile a_boardTile, Tile a_handtile)
{
	return IsValidPlacement(a_boardTile, a_handtile);
}