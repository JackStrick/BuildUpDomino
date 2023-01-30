#include "Human.h"

Human::Human()
{

}

Human::~Human()
{

}

Tile Human::Play()
{
	vector<Tile> myHand = Draw(0);
	//Print(""); Create Print Function to Send to Message Output
	cout << "\n\nYour hand: \n";
	GetHand();
	
	PlacementOptions();
	//switch

	return myHand.at(1);

}