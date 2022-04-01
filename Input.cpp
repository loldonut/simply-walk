#pragma once
#include <iostream>
#include <ncurses.h>

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

void DetectMovementInput(Player& player)
{
    while (player.m_Y <= player.limit
            && player.m_X <= player.limit)
    {
        char ch = Input();
        endwin();

        switch (ch)
        {
            // 119 = w (lowercase)
            case 119:
                player.m_Y += 50;
                std::cout << "\nWent Forwards (+50) ('w' key detected)" << std::endl;
                std::cout << "New Y Value: " << player.m_Y << std::endl;
                break;

            // 115 = s (lowercase)
            case 115:
                player.m_Y -= 50;
                std::cout << "\nWent Backwards (-50) ('s' key detected)" << std::endl;
                std::cout << "New Y Value: " << player.m_Y << std::endl;
                break;
        }

        if (player.m_Y >= player.limit)
        {
            std::cout << "Limit Reached!! (Walk Limit " << player.limit << ")" << std::endl;
            break;
        }
    }
}
