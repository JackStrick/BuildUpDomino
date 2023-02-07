#include "Round.h"
#include "MessageOutput.h"

//Default Constructor
Round::Round()
{

}

//Destructor
Round::~Round()
{
	//Ensure file is closed
	m_sfile.close();
}

//Selectors

/* *********************************************************************
Function Name: GetHumanPoints
Purpose: To get the total human points after a round
Parameters: None
Return Value: The total human points after a round
Algorithm:
			1) Calls Player::GetPoints
			2) Returns value
Assistance Received: none
********************************************************************* */
unsigned short const Round::GetHumanPoints()
{
	return m_human.GetPoints();
}

/* *********************************************************************
Function Name: GetComputerPoints
Purpose: To get the total computer points after a round
Parameters: None
Return Value: The total computer points after a round
Algorithm: 
			1) Calls Player::GetPoints
			2) Returns value
Assistance Received: none
********************************************************************* */
unsigned short const Round::GetComputerPoints()
{
	return m_computer.GetPoints();
}

/* *********************************************************************
Function Name: GetHumanRoundsWon
Purpose: To get the total rounds human won after a tournament
Parameters: None
Return Value: The total human rounds won after a round
Algorithm:
			1) Calls Player::GetRoundsWon
			2) Returns round quantity
Assistance Received: none
********************************************************************* */
unsigned short const Round::GetRoundsHumanWon()
{
	return m_human.GetRoundsWon();
}


/* *********************************************************************
Function Name: GetComputerRoundsWon
Purpose: To get the total rounds computer won after a tournament
Parameters: None
Return Value: The total computer rounds won after a round
Algorithm:
			1) Calls Player::GetRoundsWon
			2) Returns round quantity
Assistance Received: none
********************************************************************* */
unsigned short const Round::GetRoundsComputerWon()
{
	return m_computer.GetRoundsWon();
}


//Mutators
/* *********************************************************************
Function Name: SetPlayerTurn
Purpose: To set whose turn it is
Parameters: 
			a_player, an object of player type, either computer or human

Return Value: None
Algorithm:
			1) Calls Player::SetTurn() to set player turn value to true
Assistance Received: none
********************************************************************* */
void Round::SetPlayerTurn(Player& a_player)
{
	a_player.SetTurn();
}

/* *********************************************************************
Function Name: SwitchTurn
Purpose: To switch turns to next player up
Parameters: None
Return Value: None
Algorithm:
			1) Checks if its the computers turn
				a) If yes, make it the humans turn
				b) Call Player::EndTurn() which sets its turn to false
			2) If no, checks if its the humans turn
				a) If yes, make it the computers turn
				b) Call Player::EndTurn() which sets humans turn to false
Assistance Received: none
********************************************************************* */
void Round::SwitchTurn()
{
	if (m_computer.IsMyTurn())
	{
		SetPlayerTurn(m_human);
		m_computer.EndTurn();
	}
	else if (m_human.IsMyTurn())
	{
		SetPlayerTurn(m_computer);
		m_human.EndTurn();
	}
}

/* *********************************************************************
Function Name: UpdatePoints
Purpose: Updates each players point total
Parameters: None
Return Value: None
Algorithm:
			1) Loops through entire gameboard
				a) If the tile on top of stack belongs to the
					human (B), add total pips of that tile to
					human points
				b) If the tile on top of stack belongs to the
					computer (W), add total pips of that tile to
					computer points 
			2) Calls Player::Drop Points to decrease the total tile
				values left in player hand
Assistance Received: none
********************************************************************* */
void Round::UpdatePoints()
{
	// Go through entire gameboard and give points to each player
	vector<Tile> board = m_gameBoard.GetDominoStack();
	for (int i = 0; i < board.size(); i++)
	{
		if (board.at(i).getColor() == 'W')
		{
			m_computer.SetPoints(board.at(i).getTotalPips());
		}
		else if (board.at(i).getColor() == 'B')
		{
			m_human.SetPoints(board.at(i).getTotalPips());
		}
	}
	// If Tiles left in Hand - Decrease Points And Removes Tiles From Hand
	m_human.DropPoints();
	m_computer.DropPoints();
}

/* *********************************************************************
Function Name: ResetPoints
Purpose: Sets points back to zero
Parameters: None
Return Value: None
Algorithm:
			1) Calls Player::PointReset for each player to
				set the points back to zero after a round
Assistance Received: none
********************************************************************* */
void Round::ResetPoints()
{
	m_human.PointReset();
	m_computer.PointReset();
}

/* *********************************************************************
Function Name: RoundWin
Purpose: Increments users total rounds won based on who won the round
Parameters: None
Return Value: None
Algorithm:
			1) Check whose points are greater from current round
				a) If human, human wins round
				b) If computer, computer wins round
				c) If neither, its a tie
Assistance Received: none
********************************************************************* */
void Round::RoundWin()
{
	if (GetHumanPoints() > GetComputerPoints())
	{
		m_human.WonRound();
	}
	else if (GetHumanPoints() < GetComputerPoints())
	{
		m_computer.WonRound();
	}

}


//Utility Functions
/* *********************************************************************
Function Name: StartRound
Purpose: Called by tournament to begin a round
Parameters: 
			a_choice, the answer of whether to start new game
			or from a file
Return Value: None
Algorithm:
			1) Check if start new game or start from file
				a) Game is initialized based on parameter

			2) Check if each players hand is empty and also
				if the boneyards of each player are not empty
				a) If true, a new hand will start
				b) If false, start from current hand

			3) New hand: 
					a) Both players draw a tile from their 
						boneyard and compare. The larger tile holder
						goes first. If the same return tile, shuffle
						boneyard and repeat process
					b) Set the first up player and diplay to the user
					c) Both players draw the rest of their hand

			4) If not new hand, or step 3 complete:
					a) Check if either player can place a tile
					b) If yes, enter turn sequence. 
					c) Either players turn will call Choice() and return
						a vector to represent their selected tile and
						the location on the gameboard to place

			5) If done, or 4a returned false:
					a) The hand is over
					b) If players hands are not empty and there were no
						playable tiles, print to let the user know
					c) Update the score and move on to next hand if tiles
						remain in the boneyard

			6) If all hands complete and boneyards are empty
					a) Clear the gameboard 
					b) Update who won the round

Assistance Received: none
********************************************************************* */
void Round::StartRound(int a_choice)
{
	//Initializing For Data For New Game
	if (a_choice == 1)
	{
		StartNew();
	}
	
	if (a_choice == 2)
	{
		StartFromFile();
	}

	m_gameBoard.DisplayGameBoard();
	cout << "\n\n\t\t\tBuild Up";
	cout << "\n______________________________________________________________\n";
	
	while (m_handCount < 4)
	{
		int first;
		if ((m_computer.GetHand().empty() && m_human.GetHand().empty()) && !m_computer.GetBoneYard().empty() && !m_human.GetBoneYard().empty())
		{
			first = 0;
			cout << "\n\nStarting New Hand.....";
			int repeat = 3;
			do
			{
				cout << "\n\nBoth Players Drawing First Tile Of Hand";
				first = TileCompare(m_human.InitialTile(), m_computer.InitialTile());
				if (first == repeat)
				{
					cout << "\nTile Values The Same\nTiles added back to players boneyard\n\nPlayers Redrawing Tiles...";
					m_human.ReturnTiles();
					m_computer.ReturnTiles();
				}
			} while (first == repeat);

			m_msg.FirstUp(first, m_human.FirstTilePipTotal(), m_computer.FirstTilePipTotal());
			m_human.AddToHand(m_human.Draw());
			m_computer.AddToHand(m_computer.Draw());
		}

		while (IsPlaceableTiles(m_computer.GetHand()) || IsPlaceableTiles(m_human.GetHand()))
		{

			//HUMAN TURN
			if (m_human.IsMyTurn())
			{
				m_gameBoard.DisplayGameBoard();
				vector<int> tile_loc = m_human.Choice(m_gameBoard.GetDominoStack());

				
				// If Selection vector tile_loc is not empty, the tiles can be placed
				if (tile_loc.size() > 1 && tile_loc.at(0) != 89)
				{
					cout << "You are ";
					m_gameBoard.TilePlacement(m_human.GetHand().at(tile_loc[0]), tile_loc[1]);
					m_human.RemoveTileFromHand(tile_loc[0]);
				}

				// Switch turns before saving for no repeat turn
				SwitchTurn();
				//Prompt User to Save and Quit Game
				bool quit = m_msg.EndGame();
				if (quit)
				{
					SaveGame();
				}

			}
			//COMPUTER TURN
			else if (m_computer.IsMyTurn())
			{
				m_gameBoard.DisplayGameBoard();
				vector<int> tile_loc = m_computer.Choice(m_gameBoard.GetDominoStack());
				if (tile_loc.size() > 1)
				{
					m_gameBoard.TilePlacement(m_computer.GetHand().at(tile_loc[0]), tile_loc[1]);
					m_computer.RemoveTileFromHand(tile_loc[0]);
				}
				
				SwitchTurn();
			}
		}
		
		if (!m_human.GetHand().empty() && !IsPlaceableTiles(m_human.GetHand()) && !m_computer.GetHand().empty() && !IsPlaceableTiles(m_computer.GetHand()))
		{
			cout << "\n\nNo more tiles in either hand can be placed\n\n";
		}

		cout << "\nHand Complete!\nUpdating Scoreboard....";
		UpdatePoints();
		m_handCount++;	
	}

	m_gameBoard.ClearBoard();
	RoundWin();
}

/* *********************************************************************
Function Name: StartNew
Purpose: Sets up all components needed for a new game
Parameters: None
Return Value: None
Algorithm:
			1) Initialize all crucial game components for
				a brand new game
			2) Display the gameboard to the user

Assistance Received: none
********************************************************************* */
void Round::StartNew()
{
	m_roundCount = 0;
	m_handCount = 0;
	//The deck is created and shuffled for computer and human
	m_deck.GenerateTiles();

	// Human takes their 28 tiles
	m_human.Take(m_deck.Deal(m_humanType));
	// Computer takes their 28 tiles
	m_computer.Take(m_deck.Deal(m_cpuType));

	// Human Draws 6 and places them on the gameboard
	m_gameBoard.SetGameBoard(m_human.Draw());

	// Computer draws 6 and places them on the gameboard
	m_gameBoard.SetGameBoard(m_computer.Draw());
}

/* *********************************************************************
Function Name: StartFromFile
Purpose: Sets up all components needed from a past game
Parameters: None
Return Value: None
Algorithm:
			1) Asks for file path until given a valid file
			2) Set all values for computer and then human
			3) Set gameboard stacks at the end to maintain proper order
				a) The human stacks are first in the vector
			4) Determine the hand number within the round
				based on the amount of tiles in the boneyard
			4) Display the gameboard to the user

Assistance Received: none
********************************************************************* */
void Round::StartFromFile()
{
	do
	{
		// filepath hold the path of the game file entered by the user
		string filePath;
		cout << "\nPlease enter the file path: ";
		cin >> filePath;

		// Using fstream object, attempt to open file from given path
		m_sfile.open(filePath);

		// check if the file exists
		if (!m_sfile) {
			m_sfile.close();
			cin.clear();
			cout << "\n\nFile Does Not Exist.\n";
		}
	// While the file does not exist, or cannot be found, ask for a new file path
	} while (!m_sfile);

	// File found, tells the user that the game is being loaded in
	m_msg.LoadGame();

	// Stores the current line the file is on
	string line;

	// score, holds the player score given from the file
	int score;

	// rounds, holds the player rounds won given from the file
	int rounds;

	// compStacks, holds the computers stack for the gameboard
	vector<Tile> compStacks;

	// humanStacks, holds the humans stack for the gameboard
	vector<Tile> humanStacks;

	// If the file is found, check if the file is open
	if (m_sfile.is_open())
	{
		m_sfile >> line;
		//Reading Computer data
		if (line == "Computer:");
		{
			// Getting stack information
			m_sfile >> line;
			if (line == "Stacks:")
			{
				getline(m_sfile, line);
				if (line != " ")
				{
					// If the stacks are not empty, set the computers given stacks from line
					compStacks = m_computer.SetStacks(line);
				}
			}
			m_sfile >> line;
			// Getting Boneyard information
			if (line == "Boneyard:")
			{
				getline(m_sfile, line);
				if (line != " ")
				{
					// If the boneyard is not empty, set the computers boneyard from the line
					m_computer.SetBoneyard(line);
				}
			}
			m_sfile >> line;
			if (line == "Hand:")
			{
				getline(m_sfile, line);
				if (line != " ")
				{
					m_computer.SetHand(line);
				}
			}
			m_sfile >> line;
			if (line == "Score:")
			{
				m_sfile >> score;
				m_computer.PointReset();
				m_computer.SetPoints(score);
			}
			m_sfile >> line;
			m_sfile >> line;
			if (line == "Won:")
			{
				m_sfile >> rounds;
				m_computer.SetRoundsWon(rounds);
			}
			m_sfile >> line;
		}
		
		//Reading Human
		if (line == "Human:");
		{
			m_sfile >> line;
			if (line == "Stacks:")
			{
				getline(m_sfile, line);
				if (line != " ")
				{
					humanStacks = m_human.SetStacks(line);
				}
			}
			m_sfile >> line;
			if (line == "Boneyard:")
			{
				getline(m_sfile, line);
				if (line != " ")
				{
					m_human.SetBoneyard(line);
				}
			}
			m_sfile >> line;
			if (line == "Hand:")
			{
				getline(m_sfile, line);
				if (line != " ")
				{
					m_human.SetHand(line);
				}
			}
			m_sfile >> line;
			if (line == "Score:")
			{
				m_sfile >> score;
				m_human.PointReset();
				m_human.SetPoints(score);
			}
			m_sfile >> line;
			m_sfile >> line;
			if (line == "Won:")
			{
				m_sfile >> rounds;
				m_human.SetRoundsWon(rounds);
			}
		}

		m_sfile >> line;
		if (line == "Turn:")
		{
			m_sfile >> line;
			if (line == "Computer")
			{
				m_computer.SetTurn();
				m_human.EndTurn();
				cout << "\n\nComputer Will Go First\n\n";
			}
			else if (line == "Human")
			{
				m_human.SetTurn();
				m_computer.EndTurn();
				cout << "\n\nHuman Will Go First\n\n";
			}
		}
	}

	// Based on the boneyard size, determine which hand the game is on
	int bySize = m_human.GetBoneYard().size();
	switch (bySize)
	{
		case 22: 
			m_handCount = 0;
			break;
		case 16:
			m_handCount = 1;
			break;
		case 10:
			m_handCount = 2;
			break;
		case 4:
			if (m_human.GetHand().empty() && m_computer.GetHand().empty())
			{
				m_handCount = 3;
			}
			else
			{
				m_handCount = 2;
			}
			break;
		default:
			m_handCount = 3;
			break;
		
	}

	//Comp Gameboard after human gameboard
	m_gameBoard.SetGameBoard(humanStacks);
	m_gameBoard.SetGameBoard(compStacks);
	m_sfile.close();
}

/* *********************************************************************
Function Name: TileCompare
Purpose: To figure out who goes first each hand
Parameters: 
			a_human, the tile the human first drew
			a_computer, the tile the computer first drew
Return Value: 
		returns an int that refers to whose turn it will be
Algorithm:
			1) Checks which player has the larger tile
				and sets them to start first
				a) If the same, 3 is retuned which will indicate
					the need to repeat the process
Assistance Received: none
********************************************************************* */
int Round::TileCompare(Tile a_human, Tile a_computer)
{
	// If Human tile is larger than computer tile, return 1
	if (a_human.getTotalPips() > a_computer.getTotalPips())
	{
		SetPlayerTurn(m_human);
		m_computer.EndTurn();
		return 1;
	}
	// Computer tile is larger, return 2
	else if (a_human.getTotalPips() < a_computer.getTotalPips())
	{
		SetPlayerTurn(m_computer);
		m_human.EndTurn();
		return 2;
	}
	// If tiles are same value then redraw initial tile
	else
	{
		return 3;
	}

}

/* *********************************************************************
Function Name: IsPlaceableTiles
Purpose: To determine if a players tiles can be placed on the board
Parameters:
			a_playerTiles, a vector of tiles that represents a players
			hand
Return Value:
		returns a bool. 
		If true, means they have a tile that can be placed. 
		If false, they have no tiles in their hand that can be
		placed anywhere on the board
Algorithm:
			1) Loops through the entire board and checks if
				each tile matches the required criteria to be placed
Assistance Received: none
********************************************************************* */
bool Round::IsPlaceableTiles(vector<Tile>& a_playerTiles)
{
	vector<Tile> board = m_gameBoard.GetDominoStack();

	//Check first players tiles
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < a_playerTiles.size(); j++)
		{
			//Tile total pips larger than on board
			if (a_playerTiles.at(j).getTotalPips() >= board.at(i).getTotalPips())
			{
				return true;
			}
			//If a double tile, it can be placed anywhere unless the stack is a double tile greater to the one in hand
			else if (a_playerTiles.at(j).getLeftPips() == a_playerTiles.at(j).getRightPips())
			{
				if (board.at(i).getLeftPips() != board.at(i).getRightPips())
				{
					return true;
				}
				else if ((board.at(i).getLeftPips() == board.at(i).getRightPips()) && (a_playerTiles.at(j).getTotalPips() > board.at(i).getTotalPips()))
				{
					return true;
				}
			}
		}
	}

	return false;
}

/* *********************************************************************
Function Name: SaveGame
Purpose: Stores all current player data to a file
Parameters: None
Return Value: None
Algorithm:
			1) Asks for a name to give the file and creates a new file
				of that given name
			2) Pulls in all data required for the computer
			3) Pulls in all data required for the human
			4) Sets both rounds, score, and finally the player
				whose turn will be next

Assistance Received: 	
			https://stackoverflow.com/questions/5252612/replace-space-with-an-underscore
			https://www.educative.io/answers/how-to-get-the-current-date-and-time-in-cpp
			
********************************************************************* */
void Round::SaveGame()
{
	vector<Tile> temp;
	string path = "C:\\Users\\jstrickland\\Documents\\CMPS366\\";
	cout << "\n\nEnter file name to save - Do not include extension" << endl;
	//Create File Name With Data and txt File Extension
	string fileName;
	cin >> fileName;

	cout << "\n\nSaving Game to: " + path + fileName + ".txt";
	//Create New File
	ofstream file(path + fileName + ".txt");

	if (file.is_open())
	{
		//SAVE ALL COMPUTER DATA

		file << "Computer:" << endl;

		//Write Computer Stack To File
		temp = m_gameBoard.GetDominoStack();
		file << "\tStacks: ";
		for (int i = 6; i < temp.size(); i++)
		{
			file << temp.at(i).getColor();
			file << temp.at(i).getLeftPips();
			file << temp.at(i).getRightPips() << " ";
		}

		//Write Boneyard to file
		temp = m_computer.GetBoneYard();
		file << "\n\tBoneyard: ";
		for (int i = 0; i < temp.size(); i++)
		{
			file << temp.at(i).getColor();
			file << temp.at(i).getLeftPips();
			file << temp.at(i).getRightPips() << " ";
		}

		//Write Hand to file
		temp = m_computer.GetHand();
		file << "\n\tHand: ";
		for (int i = 0; i < temp.size(); i++)
		{
			file << temp.at(i).getColor();
			file << temp.at(i).getLeftPips();
			file << temp.at(i).getRightPips() << " ";
		}

		//Write Score
		file << "\n\tScore: " << m_computer.GetPoints();

		//Write Rounds Won
		file << "\n\tRounds Won: " << m_computer.GetRoundsWon();


		//SAVE ALL HUMAN DATA

		file << "\n\nHuman:" << endl;

		//Write Computer Stack To File
		temp = m_gameBoard.GetDominoStack();
		file << "\tStacks: ";
		for (int i = 0; i < temp.size() - 6; i++)
		{
			file << temp.at(i).getColor();
			file << temp.at(i).getLeftPips();
			file << temp.at(i).getRightPips() << " ";
		}

		//Write Boneyard to file
		temp = m_human.GetBoneYard();
		file << "\n\tBoneyard: ";
		for (int i = 0; i < temp.size(); i++)
		{
			file << temp.at(i).getColor();
			file << temp.at(i).getLeftPips();
			file << temp.at(i).getRightPips() << " ";
		}

		//Write Hand to file
		temp = m_human.GetHand();
		file << "\n\tHand: ";
		for (int i = 0; i < temp.size(); i++)
		{
			file << temp.at(i).getColor();
			file << temp.at(i).getLeftPips();
			file << temp.at(i).getRightPips() << " ";
		}

		//Write Score
		file << "\n\tScore: " << m_human.GetPoints();

		//Write Rounds Won
		file << "\n\tRounds Won: " << m_human.GetRoundsWon();

		//Write Turn
		if (m_computer.IsMyTurn())
		{
			file << "\n\nTurn: Computer";
		}
		else if (m_human.IsMyTurn())
		{
			file << "\n\nTurn: Human";
		}
	}

	//Close File
	file.close();

	//END PROGRAM
	exit(0);
}