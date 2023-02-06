#include "Player.h"
#include "stdafx.h"

Player::Player()
{
	//m_points = 0;
}

Player::~Player()
{

}


void Player::Take(vector<Tile> a_tiles)
{
	m_boneYard = a_tiles;
}

vector<Tile> Player::SetStacks(string a_stack)
{
	char color;
	int left;
	int right;
	vector<Tile> stackTiles;
	for (int i = 0; a_stack[i] != '\0'; i++)
	{
		if (a_stack[i] != ' ')
		{
			if (a_stack[i] == 'W' || a_stack[i] == 'B')
			{
				Tile tile(a_stack[i], a_stack[i + 1] - 48, a_stack[i + 2] - 48);
				stackTiles.push_back(tile);
			}
		}
	}
	return stackTiles;
}

void Player::SetBoneyard(string a_boneyard)
{
	char color;
	int left;
	int right;
	
	for (int i = 0; a_boneyard[i] != '\0'; i++)
	{
		if (a_boneyard[i] != ' ')
		{
			if (a_boneyard[i] == 'W' || a_boneyard[i] == 'B')
			{
				Tile tile(a_boneyard[i], a_boneyard[i + 1] - 48, a_boneyard[i + 2] - 48);
				m_boneYard.push_back(tile);
			}
		}
	}
}

void Player::SetHand(string a_hand)
{
	vector<Tile> handTiles;
	for (int i = 0; a_hand[i] != '\0'; i++)
	{
		if (a_hand[i] != ' ')
		{
			if (a_hand[i] == 'W' || a_hand[i] == 'B')
			{
				Tile tile(a_hand[i], a_hand[i + 1] - 48, a_hand[i + 2] - 48);
				handTiles.push_back(tile);
			}
		}
	}
	AddToHand(handTiles);
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
	else if (m_boneYard.size() > 4)
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
		for (int i = 0; i < 3; i++)
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

	return false;
}



/// <summary>
/// resource:
/// https://linuxhint.com/append-vector-cpp/#:~:text=Appending%20to%20a%20vector%20means,to%20append%20is%20push_back().
/// </summary>
/// <param name="a_gameboard"></param>
/// <returns></returns>
vector<vector<int>> Player::Strategy(vector<Tile> a_gameboard)
{
	vector<vector<int>> possibleMoves(2);
	
	for (int i = 0; i < a_gameboard.size(); i++)
	{
		for (int j = 0; j < GetHand().size(); j++)
		{
			if (IsValidPlacement(a_gameboard.at(i), GetHand().at(j)))
			{
				possibleMoves[0].push_back(i);
				possibleMoves[1].push_back(j);
			}
		}
	}
	
	return possibleMoves;
}

void Player::SetPoints(unsigned int a_points)
{
	m_points += a_points;
}

unsigned short Player::GetPoints()
{
	return m_points;
}

void Player::DropPoints()
{
	if (!GetHand().empty())
	{
		int handSize = GetHand().size();
		for (int i = 0; i < handSize; i++)
		{
			int pips = GetHand().at(0).getTotalPips();
			if ((m_points - pips) < 0)
			{
				m_points = 0;
			}
			else
			{
				m_points -= pips;
			}
			
			RemoveTileFromHand(0);
		}
	}
}

void Player::SetRoundsWon(unsigned short a_rounds)
{
	m_roundsWon = a_rounds;
}

void Player::PointReset()
{
	m_points = 0;
}

void Player::WonRound()
{
	m_roundsWon += 1;
}

vector<Tile> Player::GetBoneYard()
{
	return m_boneYard;
}

unsigned short Player::GetRoundsWon()
{
	return m_roundsWon;
}