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

void Hand::SetHand(vector<Tile> &a_playerTiles)
{
	for (int i = 0; i < a_playerTiles.size(); i++)
	{
		m_playerHand.push_back(a_playerTiles.at(i));
	}
}

int const Hand::InitialTilePipTotal()
{
	return m_playerHand.at(0).getTotalPips();
}

void const Hand::DisplayHand()
{
	cout << "\n\nYour Hand\n";
	for (int i = 0; i < m_playerHand.size(); i++)
	{
		cout << "{" << m_playerHand.at(i).getColor();
		cout << m_playerHand.at(i).getLeftPips();
		cout << m_playerHand.at(i).getRightPips() << "} ";
	}
	cout << "\n  ";
	for (int i = 0; i < m_playerHand.size(); i++)
	{
		cout << i << "     ";
	}
}

vector<Tile>& Hand::GetCurrentHand()
{
	return m_playerHand;
}

void Hand::Remove(unsigned int a_loc)
{
	m_playerHand.erase(m_playerHand.begin() + a_loc);
}