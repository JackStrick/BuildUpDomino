#include "MessageOutput.h"
#include "stdafx.h"

int MessageOutput::Welcome()
{
	cout << "Welcome to Build Up - The Domino Game\n";
	cout << "Would you like to play ? \n\n";

	int choice = 0;
	while ((choice != 1) && (choice != 2) && (choice != 3))
	{
		cout << "Enter the number to confirm your choice:\n" << "1) Start New Game\n2) Start From File\n3) No Thanks!\n";
		cin >> choice;
	}
	
	if (choice != 1 && choice != 2)
	{
		cout << "\nMaybe Next Time\nGoodbye!";
		return 0;
	}

	return choice;
}

void const MessageOutput::GameSetup()
{
	cout << "\n\nShuffling Player and Computer Decks.....";
	cout << "\nBoth Players Drawing Tiles....";
	cout << "\nCreating Initial Stacks....";
	cout << "\n\nGameboard Setup\n";
}

void const MessageOutput::FirstUp(int a_first, int a_humanTotal, int a_computerTotal)
{
	cout << "\nYour tile value was " << a_humanTotal;
	cout << "\nThe Computer's tile value was " << a_computerTotal;
	if (a_first == 1)
	{
		cout << "\nYour tile value was larger so you'll go first!";
		cout << "\n\nBoth Players Drawing the rest of their hand...";
	}
	else if (a_first == 2)
	{
		cout << "\nThe computer tile value was larger so the computer will go first!";
		cout << "\n\nBoth Players Drawing the rest of their hand...";
	}
}

int const MessageOutput::TileSelection()
{
	int choice;
	cout << "\n\nWhich Tile Would You Like To Place?\nOr Enter 99 For Help\n";
	cin >> choice;
	return choice;
}

int const MessageOutput::PlacementLocation()
{
	int choice;
	cout << "\nWhere would you like to place a tile?\n";
	cin >> choice;
	return choice;
}


bool MessageOutput::Continue()
{
	cout << "\nThe round has concluded\nWould you like to play a new round?\n\n";

	int choice = 0;
	while ((choice != 1) && (choice != 2))
	{
		cout << "Enter the number to confirm your choice:\n" << "1) Yes! :)\n2) No Thanks :(\n";
		cin >> choice;
	}

	if (choice != 1)
	{
		cout << "\nTournament Complete\n";
		cout << "\nCalculating Score...";
		return false;
	}

	return true;
}


void const MessageOutput::DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore)
{

}

void const MessageOutput::Finished()
{

}

