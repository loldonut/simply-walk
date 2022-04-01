#pragma once
#include <iostream>
#include <ncurses.h>
#include <string>

#include "Player.cpp"

// Ask for Input
char Input()
{
    char res;
    initscr();

    cbreak();

    res = getch();
    std::cout << "\n";

    return res;
}

void LogMovement(bool forwards, const int newYValue)
{
    std::string message = forwards == true 
        ? "\nWent Forwards (+50) ('w' key detected)"
        : "\nWent Backwards (-50) ('s' key detected)";
    std::cout << message << std::endl;
    std::cout << "New Y Value: " << newYValue << std::endl;
}

void DetectMovementInput(Player& player)
{
    bool quit = false;

    while (!quit && player.m_Y <= player.limit)
    {
        char ch = Input();
        endwin();

        switch (ch)
        {
            // 119 = w (lowercase)
            case 119:
                player.m_Y += 50;
                LogMovement(true, player.m_Y);
                break;

            // 115 = s (lowercase)
            case 115:
                player.m_Y -= 50;
                LogMovement(false, player.m_Y);
                break;

            // 114 = r (lowercase)
            case 114:
                player.m_Y = 0;
                std::cout << "Y Value has been reset to 0" << std::endl;
        }

        if (player.m_Y >= player.limit)
        {
            std::cout << "Limit Reached!! (Walk Limit " << player.limit << ")" << std::endl;
            std::cout << "\nPress Enter to Exit > ";
            std::cin.get();
            break;
        }
    }
}
