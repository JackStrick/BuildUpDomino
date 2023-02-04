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
    ///Initialize For File



    /// 
    /// If Choice is 1 Initilize New Game
    /// 
    m_numRoundsCpu = 0;
    m_numRoundsHuman = 0;
    m_numRounds = 0;
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
        m_msg.GameSetup();
        m_round.StartRound();
        ScoreGame(m_round.GetHumanPoints(), m_round.GetComputerPoints());
        m_round.ResetPoints();
        m_numRounds++;
    } while (ContinuePlaying());

    EndGame();
   
}



bool Tournament::ContinuePlaying()
{
    if (!m_msg.Continue())
    {
        return false;
    }
    return true;
}

void Tournament::ScoreGame(unsigned short a_playerScore, unsigned short a_cpuScore)
{
    m_msg.DisplayScore(a_playerScore, a_cpuScore);
    if (a_playerScore > a_cpuScore)
    {
        m_numRoundsHuman++;
        cout << "\n\nPlayer wins round";
    }
    else if (a_cpuScore > a_playerScore)
    {
        m_numRoundsCpu++;
        cout << "\n\nComputer wins round";
    }
    else if (a_cpuScore == a_playerScore)
    {
        cout << "\n\nRound ended in a tie";
    }
}

void Tournament::EndGame()
{
    m_msg.Finished(m_numRoundsCpu,m_numRoundsHuman);
}