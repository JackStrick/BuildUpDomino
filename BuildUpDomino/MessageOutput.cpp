#include "MessageOutput.h"
#include "stdafx.h"


/* *********************************************************************
Function Name: Welcome
Purpose:	Start up game menu that takes users choice to start a new
			game, start from a file, or quit
Parameters: None
Return Value:
			int choice, which represents the users entered choice
			1: Start new game
			2: Start from file
			3: Quit
Algorithm: None
Assistance Received: None
********************************************************************* */
int const MessageOutput::Welcome()
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

/* *********************************************************************
Function Name: Continue
Purpose:	Asks if the user wants to play a new round
Parameters: None
Return Value:
			bool -> True - The player wants to play a new round
			bool -> False - The player would like to end the game
Algorithm: None
Assistance Received: None
********************************************************************* */
bool const MessageOutput::Continue()
{
	cout << "\nWould you like to play a new round?\n\n";

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

/* *********************************************************************
Function Name: TileSelection
Purpose:	Asks where the user wants to place a tile
Parameters: None
Return Value:
			int choice, which represents the location of the tile 
			in the user's hand to place
Algorithm: None
Assistance Received: None
********************************************************************* */
int const MessageOutput::TileSelection()
{
	int choice;
	cout << "\n\nWhich Tile Would You Like To Place?\n";
	cin >> choice;
	return choice;
}

/* *********************************************************************
Function Name: PlacementLocation
Purpose:	Asks where the user wants to place a tile
Parameters: None
Return Value:
			int choice, which represents the location on the gameboard
			the user wants to place a tile
Algorithm: None
Assistance Received: None
********************************************************************* */
int const MessageOutput::PlacementLocation()
{
	int choice = 0;
	string location;

	do
	{
		cout << "\nWhere would you like to place a tile?\n";
		cin >> location;
		location[0] = toupper(location[0]);
	} while ((location[0] != 'B' && location[0] != 'W') || (int(location[1]) > 54 || (int(location[1]) < 49)));



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

/* *********************************************************************
Function Name: EndGame
Purpose:	The request to save and quit
Parameters: None
Return Value:
			bool -> True - If the user would like to save the game and quit
			bool -> False - If the user would like to continue playing
Algorithm: None
Assistance Received: None
********************************************************************* */
bool const MessageOutput::EndGame()
{
	int quit;
	cout << "\n\nWould you like to save and quit?\nPress 1 to Continue Playing or 0 to Save and Quit\n";
	cin >> quit;

	if (quit == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/* *********************************************************************
Function Name: GameSetup
Purpose:	Lets the user know, what is happening behind the scenes
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void const MessageOutput::GameSetup()
{
	cout << "\n\nShuffling Player and Computer Decks.....";
	cout << "\nBoth Players Drawing Tiles....";
	cout << "\nCreating Initial Stacks....";
	cout << "\n\nGameboard Setup\n";
}

/* *********************************************************************
Function Name: LoadGame
Purpose:	Lets the user know, that the game is able to initialize from
			the given file, and is loading in
Parameters: None
Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void const MessageOutput::LoadGame()
{
	cout << "\n\nLoading Game From File......\n";
}


/* *********************************************************************
Function Name: FirstUp
Purpose:	Displays which user is going to go first in a hand
Parameters: 
			a_first:
				if 1, the users tile was larger
				if 2, the computers tile was larger
			a_humanTotal, the total pips of the humans tile
			a_computerTotal, the total pips of the computer tile

Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
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

/* *********************************************************************
Function Name: DisplayScore
Purpose:	Displays the current scoreboard
Parameters:

			a_playerScore, the total human score
			a_cpuScore, the total computer score

Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void const MessageOutput::DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore)
{
	cout << "\n\n\t\tSCOREBOARD";
	cout << "\n------------------------------------------------";
	cout << "\nHuman\t\t\tComputer\n";
	cout << a_playerScore << "\t\t\t" << a_cpuScore;
}

/* *********************************************************************
Function Name: Finished
Purpose:	Displays the total rounds won by both players
Parameters:

			a_cpuRounds, the total rounds the computer won
			a_humanRounds, the total rounds the human won

Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
void const MessageOutput::RoundsScore(unsigned short a_cpuRounds, unsigned short a_humanRounds)
{
	cout << "\n\nThe round has concluded";
	cout << "\n\n\t\tSCOREBOARD";
	cout << "\n------------------------------------------------";
	cout << "\nHuman\t\t\tComputer\n";
	cout << "Rounds: " << a_humanRounds << "\t\t" << "Rounds: " << a_cpuRounds << endl;
}

/* *********************************************************************
Function Name: Finished
Purpose:	Displays the total rounds won by both players and announces
			tournament winner, or tie.
Parameters:

			a_cpuRounds, the total rounds the computer won
			a_humanRounds, the total rounds the human won

Return Value: None
Algorithm: None
Assistance Received: None
********************************************************************* */
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
		cout << "\nThe tournament has ended in a tie";
	}
	cout << "\n\nThank you for playing!\n" << endl;
}