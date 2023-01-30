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
	m_boneYard = a_tiles;
}


vector<Tile> Player::Draw(int a_amount)
{
	vector<Tile> playerHand;
	for (int i = 0; i < a_amount; i++)
	{
		int selection = rand() % m_boneYard.size();
		playerHand.push_back(m_boneYard.at(selection));
		m_boneYard.erase(m_boneYard.begin() + selection);
	}
	return playerHand;
}

void Player::AddToHand(vector<Tile> a_playerTiles)
{
	m_hand.SetHand(a_playerTiles);
}


Tile Player::InitialTile()
{
	int selection = rand() % m_boneYard.size();

	Tile playerTile = m_boneYard.at(selection);

	m_boneYard.erase(m_boneYard.begin() + selection);

	m_hand.InitialTile(playerTile);

	return playerTile;
}


/*



	Resources:
	https://www.tutorialspoint.com/how-to-print-out-the-contents-of-a-vector-in-cplusplus

*/
void const Player::DisplayTiles()
{
	for (int i = 0; i < m_boneYard.size(); i++)
	{
		cout << "{"  << m_boneYard.at(i).getColor();
		cout << m_boneYard.at(i).getLeftPips();
		cout << m_boneYard.at(i).getRightPips() << "} ";
	}
}

void Player::ReturnTiles()
{
	Tile playerTile = m_hand.GetInitialTile();
	m_hand.ClearHand();
	m_boneYard.push_back(playerTile);
}

int const Player::FirstTilePipTotal()
{
	return m_hand.InitialTilePipTotal();
}

void const Player::GetHand()
{
	m_hand.DisplayHand();
}

void Player::IsTurn()
{
	m_myTurn = true;
}

bool Player::MyTurn()
{
	return m_myTurn;
}

void Player::PlacementOptions()
{
	
}

/*int* Player::Strategy()
{
	int* pos;
	return pos;
}*/
