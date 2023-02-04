#pragma once
class MessageOutput
{
public:
	MessageOutput() {};
	~MessageOutput() {};

	//Welcome - Initial User Greeting
	int Welcome();

	void const GameSetup();

	void const FirstUp(int a_first, int a_humanTotal, int a_computerTotal);
	//Continue - Asks the user if they want to keep playing the tournament
	bool Continue();

	void const DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore);
	void const Finished(unsigned short a_cpuRounds, unsigned short a_humanRounds);
	int const PlacementLocation();
	int const TileSelection();
	//void ShowPossibleMoves(vector<vector<int>> a_moves);



};

