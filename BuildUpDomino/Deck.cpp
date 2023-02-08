#include "Deck.h"

Deck::Deck()
{

}

Deck::~Deck()
{

}

/* *********************************************************************
Function Name: Deal
Purpose: Deals white or black tiles to player based on type (which player)
Parameters:
			a_type, stores integer of which player is asking for tiles
				1 = Human Type
				2 = Computer Type
Return Value:
			vector<int> that contains all tiles for players boneyard
Algorithm:
			1) Checks which player is asking for tiles
				a) If Human, give human (black) tiles
				b) If Computer, give computer (white) tiles
		
Assistance Received: none
********************************************************************* */
vector<Tile> const Deck::Deal(unsigned short a_type)
{
	if (a_type == m_humanType)
	{
		return m_blackTiles;
	}
	else if (a_type == m_cpuType)
	{
		return m_whiteTiles;
	}
}


/* *********************************************************************
Function Name: GenerateTiles
Purpose: Creates each tile object in the deck
Parameters: None
Return Value: None
Algorithm:
			1) Black Tiles: 
				a) For loop for all possible tile pip combination
				b) Adds them to a vector of tiles
				c) Shuffle the entire deck of black tiles


			2) White Tiles: 
				a) For loop for all possible tile pip combination
				b) Adds them to a vector of tiles
				c) Shuffle the entire deck of white tiles

Assistance Received: None
********************************************************************* */
void Deck::GenerateTiles()
{
	m_blackTiles.clear();
	for (int leftPips = 0; leftPips < 7; leftPips++)
	{
		for (int rightPips = leftPips; rightPips < 7; rightPips++)
		{
			Tile tile('B', leftPips, rightPips);
			m_blackTiles.push_back(tile);
		}
	}

	ShuffleDeck(m_blackTiles);

	m_whiteTiles.clear();
	for (int leftPips = 0; leftPips < 7; leftPips++)
	{
		for (int rightPips = leftPips; rightPips < 7; rightPips++)
		{
			Tile tile('W', leftPips, rightPips);
			m_whiteTiles.push_back(tile);
		}
	}

	ShuffleDeck(m_whiteTiles);
}



/* *********************************************************************
Function Name: ShuffleDeck
Purpose: Shuffles the deck of tiles randomly
Parameters: 
		a_tiles, which is the entire deck of white or black tiles
Return Value: None
Algorithm:
			1) Generartes random number and performs 
				random_shuffles to shuffle the deck tiles
		
Assistance Received: 
	https://stackoverflow.com/questions/13459953/random-shuffle-not-really-random
	I was having an issue that my shuffle wasn't changing the number
	So the suggestion was to add srand(time()) in order for the number
	to change 
********************************************************************* */
void Deck::ShuffleDeck(vector<Tile> &a_Tiles)
{
	srand(time(0));
	random_shuffle(a_Tiles.begin(), a_Tiles.end());
}

