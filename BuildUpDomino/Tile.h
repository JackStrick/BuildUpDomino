#pragma once
class Tile
{


public:
	// Constructor
	Tile(char color, int leftPips, int rightPips);

	// Destructor
	~Tile();

	// Copy Constructure




	// Selectors
	const char getColor();
	const int getLeftPips();
	const int getRightPips();
	const int getTotalPips();


private:
	// Data Members
	char m_Color; 
	int m_LeftPips;
	int m_RightPips;
};

