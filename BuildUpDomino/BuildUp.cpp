/************************************************************
* Name:  Jack Strickland
* Project : 1 - Build Up C++
* Class : CMPS366 Organization of Programming Languages
* Date : 2/8/2023
************************************************************/
// BuildUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "stdafx.h"
#include "Tournament.h"
#include "MessageOutput.h"

using namespace std;

int main( int argc, char *argv[])
{
    // Initialize Message Output Class To User
    MessageOutput msg;

    // Display Welcome Screen and Check if the user wants to play
    int choice = msg.Welcome();

    //If the choice returned 0, the user doesn't want to play
    if (choice == 0)
    {
        //End Program
        return 0;
    }

    // Initialize Tournament Object/Class
    Tournament game;

    // Begin Game - The choice integer determines if new game or from file
    game.StartGame(choice);
}

