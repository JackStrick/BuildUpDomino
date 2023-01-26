#include "Deck.h"

Deck::Deck()
{

}

Deck::~Deck()
{

}

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

/*


	Resources:
	https://stackoverflow.com/questions/13459953/random-shuffle-not-really-random
*/
void Deck::ShuffleDeck(vector<Tile> &a_Tiles)
{
	srand(time(0));
	random_shuffle(a_Tiles.begin(), a_Tiles.end());
}

vector<Tile> Deck::Deal(unsigned short a_type)
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