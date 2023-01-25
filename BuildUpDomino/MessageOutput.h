#pragma once
class MessageOutput
{
public:
	MessageOutput() {};
	~MessageOutput() {};

	//Welcome - Initial User Greeting
	int Welcome();

	//Continue - Asks the user if they want to keep playing the tournament
	bool Continue();

	void DisplayScore(unsigned short a_playerScore, unsigned short a_cpuScore);
	void Finished();

};

