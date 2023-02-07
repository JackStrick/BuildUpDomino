//
//		Tournament class.  This is a container for all the components
//		that make up the tournament.
//
#pragma once

#include "MessageOutput.h"
#include "Round.h"

class Tournament
{
public:
	// Default Constructor 
	Tournament();

	// Default Destructor
	~Tournament();

	// Utility Functions 

	// Start Game - Begins the program by initializing setup
	void StartGame(int a_choice);

	// Continue Playing - Determines # of rounds based on user
	bool ContinuePlaying();

	// Get Current Score of Game
	void ScoreGame();

	// User Done With The Game - End
	void EndGame();

private:
	// Private Objects
	MessageOutput m_msg;
	Round m_round;

	// Data Members
	unsigned short m_numRounds;


};

