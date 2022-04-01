#include <iostream>
#include <ncurses.h>

#include "Player.cpp"
#include "Input.cpp"

int main()
{
    Player player;
    DetectMovementInput(player);
}
