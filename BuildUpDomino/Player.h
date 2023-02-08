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
	// Default Constructor
	Player();
	// Default Destructor
	~Player();

	// Selector
	vector<Tile>& GetHand();
	vector<Tile> const GetBoneYard();
	int const FirstTilePipTotal();
	bool const IsMyTurn();
	virtual vector<int> Choice(vector<Tile> a_gameBoardStack) = 0;
	void const ShowHand();
	bool const Play(Tile a_boardTile, Tile a_handtile);
	unsigned short const GetPoints();
	unsigned short const GetRoundsWon();
	void const DisplayBoneyard();
	

	// Mutator
	void Take(vector<Tile> a_tiles);
	vector<Tile> Draw();
	vector<Tile> SetStacks(string a_stack);
	void SetBoneyard(string a_boneyard);
	void SetHand(string a_hand);
	void PointReset();
	void SetPoints(unsigned int a_points);
	void SetRoundsWon(unsigned short a_rounds);
	void SetTurn();
	void EndTurn();	
	void ReturnTiles();
	void AddToHand(vector<Tile> a_playerTiles);
	void RemoveTileFromHand(unsigned int a_loc);
	void DropPoints();
	void WonRound();

	// Utility Functions
	void ShuffleBoneyard();
	Tile InitialTile();
	vector<vector<int>> Strategy(vector<Tile> a_gameboard);
	bool IsValidPlacement(Tile a_boardTile, Tile a_handtile);
	bool IsValidPlaceableTile(vector<Tile>& a_playerTiles, vector<Tile>& a_gameBoardTiles);
	
private:
	// Player's Individual Hand
	Hand m_hand;

	// Data Members
	vector<Tile> m_boneYard;
	unsigned short m_points;
	bool m_myTurn;
	unsigned short m_roundsWon;

};

