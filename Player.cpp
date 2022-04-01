#pragma once
#include <iostream>

class Player
{
public:
    int m_X;
    int m_Y;
    int limit;

    enum DirectionType
    {
        FORWARD = 0, BACKWARD
    };

    Player()
    {
        m_X = 0;
        m_Y = 0;
        limit = 400;
    }
};
