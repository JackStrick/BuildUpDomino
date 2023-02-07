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


	virtual vector<int> Choice(vector<Tile> a_gameBoardStack) = 0;

	bool Play(Tile a_boardTile, Tile a_handtile);

	void Take(vector<Tile> a_tiles);

	vector<Tile> Draw();

	Tile InitialTile();

	void ReturnTiles();

	void ShuffleBoneyard();

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

	bool IsValidPlaceableTile(vector<Tile>& a_playerTiles, vector<Tile>& a_gameBoardTiles);

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

