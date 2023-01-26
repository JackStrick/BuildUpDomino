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


vector<Tile> Player::Draw(int a_amount)
{
	vector<Tile> playerHand;
	for (int i = 0; i < a_amount; i++)
	{
		int selection = rand() % m_playerTiles.size();
		playerHand.push_back(m_playerTiles.at(selection));
		m_playerTiles.erase(m_playerTiles.begin() + selection);
	}
	return playerHand;
}

void Player::AddToHand(vector<Tile> a_playerTiles)
{
	m_hand.SetHand(a_playerTiles);
}


Tile Player::InitialTile()
{
	int selection = rand() % m_playerTiles.size();

	Tile playerTile = m_playerTiles.at(selection);

	m_playerTiles.erase(m_playerTiles.begin() + selection);

	m_hand.InitialTile(playerTile);

	return playerTile;
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

void Player::ReturnTiles()
{
	Tile playerTile = m_hand.GetInitialTile();
	m_hand.ClearHand();
	m_playerTiles.push_back(playerTile);
}

int Player::FirstTilePipTotal()
{
	return m_hand.InitialTilePipTotal();
}

void Player::GetHand()
{
	m_hand.DisplayHand();
}
