#include "Hand.h"

Hand::Hand()
{

}

Hand::~Hand()
{

}

/* *********************************************************************
Function Name: GetInitialTile
Purpose:	Grabs the players first tile that will be used to determine
			who goes first
Parameters: None
Return Value: 
			Tile Object
Algorithm:
			1) Since the hands are shuffled we can grab the tile at
				the first position

Assistance Received: None
********************************************************************* */
Tile Hand::GetInitialTile()
{
	Tile tile = m_playerHand.at(0);
	return tile;
}

/* *********************************************************************
Function Name: InitialTilePipTotal
Purpose:	Checks the total pips at players first tile
Parameters: None
Return Value:
			int value of the players first tiles' total pips
Algorithm:
			1) Gets the tiles in the first position, total pips
				and returns the value

Assistance Received: None
********************************************************************* */
int const Hand::InitialTilePipTotal()
{
	return m_playerHand.at(0).getTotalPips();
}

/* *********************************************************************
Function Name: GetCurrentHand
Purpose:	Returns a vector of tile objects that represents
			a players current hand
Parameters: None
Return Value:
			vector<Tile> - Vector of tile objects
Algorithm: None
Assistance Received: None
********************************************************************* */
vector<Tile>& Hand::GetCurrentHand()
{
	return m_playerHand;
}

/* *********************************************************************
Function Name: InitialTile
Purpose:	Adds the initial tile to a users hand
Parameters: 
			Tile Object - first tile being taken from boneyard
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void Hand::InitialTile(Tile a_tile)
{
	m_playerHand.push_back(a_tile);
}


/* *********************************************************************
Function Name: SetHand
Purpose:	Sets a players hand during the game
Parameters:
			a_playerTiles, a vector of tiles that represents 
			tiles that can be added to the hand
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void Hand::SetHand(vector<Tile>& a_playerTiles)
{
	for (int i = 0; i < a_playerTiles.size(); i++)
	{
		m_playerHand.push_back(a_playerTiles.at(i));
	}
}

/* *********************************************************************
Function Name: ClearHand
Purpose:	Clear any tiles left in the player hand vector<Tile>
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void Hand::ClearHand()
{
	m_playerHand.clear();
}

/* *********************************************************************
Function Name: Remove
Purpose:	Remove the tile at given location to erase a specific tile
			object from the player's hand 
Parameters: 
			a_loc, the location in the hand vector to remove a
			tile from
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void Hand::Remove(unsigned int a_loc)
{
	m_playerHand.erase(m_playerHand.begin() + a_loc);
}

/* *********************************************************************
Function Name: DisplayHand
Purpose:	Display the users hand
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void const Hand::DisplayHand()
{
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