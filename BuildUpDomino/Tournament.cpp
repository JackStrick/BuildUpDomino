//
//		Implementation of the Tournament Class
//

#include "Tournament.h"


Tournament::Tournament()
{

}

Tournament::~Tournament()
{
}

/*
NAME

    StartGame - 

SYNOPSIS

    void Tournament::StartGame();

DESCRIPTION

    Initializes everything needed to begin the game and launch 
    each round. The tournament will control all rounds and track 
    the score after each round.
*/
void Tournament::StartGame()
{

    do
    {
        //m_round.StartRound();
    } while (ContinuePlaying());

    ScoreGame();
}



bool Tournament::ContinuePlaying()
{
    if (!m_msg.Continue())
    {
        return false;
    }
    return true;
}

void Tournament::ScoreGame()
{

}