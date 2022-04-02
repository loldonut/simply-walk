#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

#include "Player.cpp"
#include "Input.cpp"

void Start(int argc, char** argv)
{
    std::string WalkLimitString = argc > 1 ? argv[1] : "400";
    int WalkLimit = WalkLimitString != "400" 
                    ? stoi(WalkLimitString)
                    : 400;

    Player player;
    if (WalkLimit != 400 && WalkLimit > 0)
        player.limit = WalkLimit;
    else 
    {
        std::cerr << "PlayerError: Walk Limit cannot be negative" << std::endl;
        return;
    }

    DetectMovementInput(player);
}
