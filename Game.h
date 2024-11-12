#pragma once
#include "Card.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

class Game
{
public:
    int PlayerScore;
    int DealerScore;

    Game() : PlayerScore(0), DealerScore(0) {}

    void DrawCardPlayer(int &score);
    void DrawCardDealer(int &score);
    void ShowPlayerScore();
    void ShowDealerScore();
    void GameLoop();
};


