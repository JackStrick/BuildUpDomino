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

void const MessageOutput::LoadGame()
{
	cout << "\n\nLoading Game From File......\n";
}

void const MessageOutput::FirstUp(int a_first, int a_humanTotal, int a_computerTotal)
{
	cout << "\nYour tile value was " << a_humanTotal;
	cout << "\nThe Computer's tile value was " << a_computerTotal;
	if (a_first == 1)
	{
		cout << "\nYour tile value was larger so you'll go first!";
	}
	else if (a_first == 2)
	{
		cout << "\nThe computer tile value was larger so the computer will go first!";
	}
	cout << "\n\nBoth Players Drawing the rest of their hand...";
}

int const MessageOutput::TileSelection()
{
	int choice;
	cout << "\n\nWhich Tile Would You Like To Place?\n";
	cin >> choice;
	return choice;
}

int const MessageOutput::PlacementLocation()
{
	int choice = 0;
	string location;

	do
	{
		cout << "\nWhere would you like to place a tile?\n";
		cin >> location;
		location[0]=toupper(location[0]);
	} while ((location[0] != 'B' && location[0] != 'W') && (int(location[1]) > 6 || (int(location[1]) < 1)));
	

	
	if (location[0] == 'B')
	{
		choice = int(location[1]) - 49;
	}
	else if (location[0] == 'W')
	{
		choice = int(location[1]) - 43;
	}
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

/*void MessageOutput::ShowPossibleMoves(vector<vector<int>> a_moves)
{

}*/

void const MessageOutput::DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore)
{
	cout << "\n\n\t\tSCOREBOARD";
	cout << "\n------------------------------------------------";
	cout << "\nHuman\t\t\tComputer\n";
	cout << a_playerScore << "\t\t\t" << a_cpuScore;
}

void const MessageOutput::Finished(unsigned short a_cpuRounds, unsigned short a_humanRounds)
{
	cout << "\n\n\t\tSCOREBOARD";
	cout << "\n------------------------------------------------";
	cout << "\nHuman\t\t\tComputer\n";
	cout << "Rounds: " << a_humanRounds << "\t\t" << "Rounds: " << a_cpuRounds << endl;
	if (a_cpuRounds > a_humanRounds)
	{
		cout << "\nThe computer has won :(";
	}
	else if (a_cpuRounds < a_humanRounds)
	{
		cout << "\nYou have won!";
	}
	else if (a_cpuRounds == a_humanRounds)
	{
		cout << "\nThe torunament has ended in a tie";
	}

	cout << "\n\nThank you for playing!\n" << endl;
}


