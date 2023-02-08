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
	// Default Constructor
	Round();
	// Default Destructor
	~Round();

	// Selectors
	unsigned short const GetHumanPoints();
	unsigned short const GetComputerPoints();
	unsigned short const GetRoundsHumanWon();
	unsigned short const GetRoundsComputerWon();

	// Mutator
	void SetPlayerTurn(Player &a_player);
	void SwitchTurn();
	void UpdatePoints();
	void ResetPoints();
	void RoundWin();

	// Utility Functions
	void StartRound(int a_choice);
	void StartNew();
	void StartFromFile();
	int TileCompare(Tile a_human, Tile a_computer);
	bool IsPlaceableTiles(vector<Tile>& a_playerHand);
	void SaveGame();

private:
	//Private Class Objects
	Human m_human;
	Computer m_computer;
	Deck m_deck;
	GameBoard m_gameBoard;
	Hand m_hand;
	MessageOutput m_msg;
	fstream m_sfile;

	//Data Members
	unsigned short m_handCount;
	unsigned short m_roundCount;
	unsigned short m_humanType = 1;
	unsigned short m_cpuType = 2;

};

