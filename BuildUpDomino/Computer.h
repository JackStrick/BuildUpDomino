#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	Computer();
	~Computer();

	void Choice();

private:
	char m_tileColor = 'W';
};

