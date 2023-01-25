#include "Player.h"
#include "stdafx.h"

Player::Player()
{
	m_points = 0;
}

Player::~Player()
{

}

void Player::Play()
{

}

void Player::Take(vector<Tile> a_tiles)
{
	m_playerTiles = a_tiles;
}


vector<Tile> Player::Draw()
{
	vector<Tile> playerHand;
	for (int i = 0; i < 6; i++)
	{
		int selection = rand() % m_playerTiles.size();
		m_playerTiles.erase(m_playerTiles.begin() + selection);
	}
	return playerHand;
}


/*



	Resources:
	https://www.tutorialspoint.com/how-to-print-out-the-contents-of-a-vector-in-cplusplus

*/
void Player::DisplayTiles()
{
	for (int i = 0; i < m_playerTiles.size(); i++)
	{
		cout << "{"  << m_playerTiles.at(i).getColor();
		cout << m_playerTiles.at(i).getLeftPips();
		cout << m_playerTiles.at(i).getRightPips() << "} ";
	}
}
