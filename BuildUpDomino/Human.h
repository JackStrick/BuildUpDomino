#pragma once
#include "Player.h"
class Human : public Player
{
public:
	Human();
	~Human();

	void Choice();


private:
	char m_tileColor = 'B';

};

