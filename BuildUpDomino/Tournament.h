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
	Tournament();
	~Tournament();

	//Start Game - Begins the program by initializing setup
	void StartGame();

	//Continue Playing - Determines # of rounds based on user
	bool ContinuePlaying();

	void ScoreGame();

private:

	MessageOutput m_msg;
	Round m_round;


};

