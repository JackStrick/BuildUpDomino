#include "Computer.h"

Computer::Computer()
{

}

Computer::~Computer()
{

}

void Computer::Play()
{
	cout << "\n\nComputer's hand: \n";
	GetHand();
	Strategy();
}