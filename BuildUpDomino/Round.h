//
//		Round class - handles each round within the tournament
//
#pragma once

#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Deck.h"
#include "GameBoard.h"
#include "Hand.h"
#include "MessageOutput.h"

class Round
{
public:
	Round();
	~Round();

	void StartRound();
	int TileCompare(Tile a_human, Tile a_computer);
	void SetTurn(Player a_player);
	void SwitchTurn();


private:
	// Class Objects
	Human m_human;
	Computer m_computer;
	Deck m_deck;
	GameBoard m_gameBoard;
	Hand m_hand;
	MessageOutput m_msg;


	unsigned short m_humanType = 1;
	unsigned short m_cpuType = 2;

};

