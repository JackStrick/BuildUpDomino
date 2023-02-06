//
//		Implementation of the Tournament Class
//

#include "Tournament.h"


Tournament::Tournament()
{

}

Tournament::~Tournament()
{
    m_sfile.close();
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
    ///Initialize For New Game
    if (a_choice == 1)
    {
        m_numRounds = 0;
    }

    do
    {
        if (a_choice == 1)
        {
            m_msg.GameSetup();
        }
       
        m_round.StartRound(a_choice);
        ScoreGame();
        m_round.ResetPoints();
        m_numRounds++;
    } while (ContinuePlaying());

    EndGame();
   
}
/*
void Tournament::StartFromFile()
{
    do
    {
        string filePath = m_msg.GetFileFromUser();

        m_sfile.open(filePath);

        if (!m_sfile) {
            cout << "\n\nFile Does Not Exist.\n";
        }
    } while (!m_sfile); 
}*/

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
    int human = m_round.GetHumanPoints();
    int cpu = m_round.GetComputerPoints();
    m_msg.DisplayScore(human, cpu);
    if (human > cpu)
    {
        cout << "\n\nPlayer wins round";
    }
    else if (cpu > human)
    {
        cout << "\n\nComputer wins round";
    }
    else if (cpu == human)
    {
        cout << "\n\nRound ended in a tie";
    }
}

void Tournament::EndGame()
{
    m_msg.Finished(m_round.GetRoundsComputerWon(), m_round.GetRoundsHumanWon());
}