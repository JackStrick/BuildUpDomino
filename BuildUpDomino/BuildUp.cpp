// BuildUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "Tournament.h"
#include "MessageOutput.h"

using namespace std;

int main()
{
    // Initialize Message Output Class To User
    MessageOutput msg;

    // Check if the user wants to play
    if (!msg.Welcome()) 
    {
        return 0;
    }

    // Initialize Tournament Object/Class
    Tournament game;

    // Begin Game
    game.StartGame();
}

