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
	// Constructor 
	Tournament();

	// Destructor
	~Tournament();

	//Start Game - Begins the program by initializing setup
	void StartGame(int a_choice);

	//Continue Playing - Determines # of rounds based on user
	bool ContinuePlaying();

	// Get Current Score of Game
	void ScoreGame(unsigned short m_playerScore, unsigned short m_cpuScore);

	// User Done With The Game - End
	void EndGame();

private:
	//FileReader m_file;
	MessageOutput m_msg;
	Round m_round;

	// Variables
	unsigned short m_numRoundsCpu;
	unsigned short m_numRoundsHuman;
	unsigned short m_numRounds;


};

