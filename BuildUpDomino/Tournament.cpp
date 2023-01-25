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
void Tournament::StartGame(int a_choice)
{
    m_cpuScore = 0;
    m_playerScore = 0;
    //Choice will determine if new game or from file
   /* switch (a_choice)
    {
        case 1: 
            StartNew;
            break;
        case 2: 
            StartFromFile;
            break;
    }
    
   */
    do
    {
        m_round.StartRound();
        ScoreGame(m_playerScore, m_cpuScore);
    } while (ContinuePlaying());

   
}



bool Tournament::ContinuePlaying()
{
    if (!m_msg.Continue())
    {
        return false;
    }
    return true;
}

void Tournament::ScoreGame(unsigned short m_playerScore, unsigned short m_cpuScore)
{
    m_msg.DisplayScore(m_playerScore, m_cpuScore);
}

void Tournament::EndGame(unsigned short m_numRounds, unsigned short m_playerScore, unsigned short m_cpuScore)
{
    m_msg.Finished();
    ScoreGame(m_playerScore, m_cpuScore);
}