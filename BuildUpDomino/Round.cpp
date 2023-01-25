#include "Round.h"

Round::Round()
{

}

Round::~Round()
{

}

void Round::StartRound()
{
	m_deck.GenerateTiles();
	m_human.Take(m_deck.Deal(m_humanType));
	m_computer.Take(m_deck.Deal(m_cpuType));

	//m_human.DisplayTiles();
	//m_computer.DisplayTiles();

	m_gameBoard.SetGameBoard(m_human.Draw());
	m_gameBoard.SetGameBoard(m_computer.Draw());

	m_gameBoard.GetDominoStack();
	

}