#pragma once
class MessageOutput
{
public:
	MessageOutput() {};
	~MessageOutput() {};

	//Welcome - Initial User Greeting
	bool Welcome();

	//Continue - Asks the user if they want to keep playing the tournament
	bool Continue();
};

