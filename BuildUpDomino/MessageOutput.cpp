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
		cout << "Maybe Next Time\nGoodbye!";
		return 0;
	}

	return choice;
}

bool MessageOutput::Continue()
{
	cout << "The round has concluded\nWould you like to play a new round?\n\n";

	int choice = 0;
	while ((choice != 1) && (choice != 2))
	{
		cout << "Enter the number to confirm your choice:\n" << "1) Yes! :)\n2) No Thanks :(\n";
		cin >> choice;
	}

	if (choice != 1)
	{
		cout << "\nTournament Complete\n";
		cout << "Calculating Score...";
		return false;
	}

	return true;
}


void MessageOutput::DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore)
{

}

void MessageOutput::Finished()
{

}

