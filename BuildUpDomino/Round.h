//
//		Round class - handles each round within the tournament
//
#pragma once


#include "Human.h"
#include "Computer.h"
#include "Deck.h"
#include "GameBoard.h"

class Round
{
public:
	Round();
	~Round();

	void StartRound();


private:
	// Class Objects
	Human m_human;
	Computer m_computer;
	Deck m_deck;
	GameBoard m_gameBoard;


	unsigned short m_humanType = 1;
	unsigned short m_cpuType = 2;

};

