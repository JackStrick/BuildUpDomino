#pragma once
class MessageOutput
{
public:
	// Default Constructor
	MessageOutput() {};
	// Default Destructor
	~MessageOutput() {};

	// Selectors
	int const Welcome();
	bool const Continue();
	int const TileSelection();
	int const PlacementLocation();
	bool const EndGame();

	// Utility Functions
	void const GameSetup();
	void const LoadGame();
	void const FirstUp(int a_first, int a_humanTotal, int a_computerTotal);
	void const DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore);
	void const Finished(unsigned short a_cpuRounds, unsigned short a_humanRounds);

};
