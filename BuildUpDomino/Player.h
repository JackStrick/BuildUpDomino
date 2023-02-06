//
// Player Class
//
#pragma once


#include "Tile.h"
#include "Hand.h"
#include "stdafx.h"

class Player
{
public:
	Player();
	~Player();



	virtual bool Play(Tile a_boardTile, Tile a_handtile) = 0;

	void Take(vector<Tile> a_tiles);

	vector<Tile> Draw();

	Tile InitialTile();

	void ReturnTiles();

	void const DisplayBoneyard();

	void AddToHand(vector<Tile> a_playerTiles);

	vector<Tile>& GetHand();

	void RemoveTileFromHand(unsigned int a_loc);

	void const ShowHand();

	int const FirstTilePipTotal();

	void SetTurn();

	bool IsMyTurn();

	void EndTurn();

	bool IsValidPlacement(Tile a_boardTile, Tile a_handtile);

	vector<vector<int>> Strategy(vector<Tile> a_gameboard);

	// Selectors
	unsigned short GetPoints();

	void SetPoints(unsigned int a_points);
	void DropPoints();
	void PointReset();
	void WonRound();

	vector<Tile> SetStacks(string a_stack);
	
	
	void SetBoneyard(string a_boneyard);

	void SetHand(string a_hand);

	void SetRoundsWon(unsigned short a_rounds);

	/*
	void SetHand();
	void SetPointsFromFile();
	void SetRoundsWon();
	
	*/
	vector<Tile> GetBoneYard();

	unsigned short GetRoundsWon();


private:
	// Private Objects
	Hand m_hand;


	// Data Members
	unsigned short m_points;
	bool m_myTurn;
	unsigned short m_roundsWon;
	vector<Tile> m_boneYard;

};

