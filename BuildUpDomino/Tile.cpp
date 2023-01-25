#include "Tile.h"

Tile::Tile(char color, int leftPips, int rightPips)
{
	m_Color = color;
	m_LeftPips = leftPips;
	m_RightPips = rightPips;
}

Tile::~Tile()
{

}

const char Tile::getColor()
{
	return m_Color;
}

const int Tile::getLeftPips()
{
	return m_LeftPips;
}
const int Tile::getRightPips()
{
	return m_RightPips;
}

const int Tile::getTotalPips()
{
	return m_LeftPips + m_RightPips;
}