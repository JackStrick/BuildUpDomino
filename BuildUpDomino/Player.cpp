#include "Player.h"
#include "stdafx.h"

Player::Player()
{
	m_points = 0;
}

Player::~Player()
{

}


void Player::Take(vector<Tile> a_tiles)
{
	m_boneYard = a_tiles;
}


vector<Tile> Player::Draw()
{
	vector<Tile> playerHand;
	// 6 Tiles for creating gameboard
	if(m_boneYard.size() == 28)
	{
		for (int i = 0; i < 6; i++)
		{
			int selection = rand() % m_boneYard.size();
			playerHand.push_back(m_boneYard.at(selection));
			m_boneYard.erase(m_boneYard.begin() + selection);
		}
	}
	// 5 Tiles while not last hand 
	else if (m_boneYard.size() > 6)
	{
		for (int i = 0; i < 5; i++)
		{
			int selection = rand() % m_boneYard.size();
			playerHand.push_back(m_boneYard.at(selection));
			m_boneYard.erase(m_boneYard.begin() + selection);
		}
	}
	// 4 Tiles for last hand
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int selection = rand() % m_boneYard.size();
			playerHand.push_back(m_boneYard.at(selection));
			m_boneYard.erase(m_boneYard.begin() + selection);
		}
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
void const Player::DisplayBoneyard()
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

vector<Tile>& Player::GetHand()
{
	return m_hand.GetCurrentHand();
}

void Player::RemoveTileFromHand(unsigned int a_loc)
{
	m_hand.Remove(a_loc);
}

void const Player::ShowHand()
{
	m_hand.DisplayHand();
}

void Player::SetTurn()
{
	m_myTurn = true;
}

bool Player::IsMyTurn()
{
	return m_myTurn;
}

void Player::EndTurn()
{
	m_myTurn = false;
}

bool Player::IsValidPlacement(Tile a_boardTile, Tile a_handtile)
{
	if (a_handtile.getTotalPips() >= a_boardTile.getTotalPips())
	{
		return true;
	}
	else if (a_handtile.getLeftPips() == a_handtile.getRightPips())
	{
		if ((a_boardTile.getLeftPips() != a_boardTile.getRightPips()))
		{
			return true;
		}
		else if ((a_boardTile.getLeftPips() == a_boardTile.getRightPips()) && (a_handtile.getTotalPips() > a_boardTile.getTotalPips()))
		{
			return true;
		}
	}

	cout << "\nThis Tile Cannot Be Placed Here\n";
	return false;
}




/*int* Player::Strategy()
{
	int* pos;
	return pos;
}*/

void Player::SetPoints(unsigned int a_points)
{
	m_points += a_points;
}