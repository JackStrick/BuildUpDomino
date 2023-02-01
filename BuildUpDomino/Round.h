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
	void SetPlayerTurn(Player &a_player);
	bool IsPlaceableTiles(vector<Tile> &a_player1Hand, vector<Tile> &a_player2Hand);
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

