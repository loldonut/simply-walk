#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

#include "Player.cpp"
#include "Input.cpp"

void Start(int argc, char** argv)
{
    std::string WalkLimitString = argc > 1 ? argv[1] : "400";
    int WalkLimit = 400;

    if (argc >= 1)
        WalkLimit = stoi(WalkLimitString);

    Player player;
    if (WalkLimit != 400)
    {
        player.limit = WalkLimit;
    }
    else if (WalkLimit < 0)
    {
        std::cout << "PlayerError: Walk Limit cannot be negative" << std::endl;
    }

    DetectMovementInput(player);
}