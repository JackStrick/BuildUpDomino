#pragma once
class Player
{
public:
	Player(){}


private:

};

class HumanPlayer:public Player {
public:
	HumanPlayer():Player() {	}

};

class CPUPlayer:public Player {
public:
	CPUPlayer():Player() { }


};
