#include "Hand.h"

Hand::Hand()
{

}

Hand::~Hand()
{

}

void Hand::InitialTile(Tile a_tile)
{
	m_playerHand.push_back(a_tile);
}

void Hand::ClearHand()
{
	m_playerHand.clear();
}

Tile Hand::GetInitialTile()
{
	Tile tile = m_playerHand.at(0);
	return tile;
}

void Hand::SetHand(vector<Tile> a_playerTiles)
{
	for (int i = 0; i < a_playerTiles.size(); i++)
	{
		m_playerHand.push_back(a_playerTiles.at(i));
	}
}

int Hand::InitialTilePipTotal()
{
	return m_playerHand.at(0).getTotalPips();
}

