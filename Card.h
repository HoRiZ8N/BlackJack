#pragma once
#include <string>
#include <ctime>
#include <cstdlib>

class Card
{
private:
    std::string name;
    int value;
    std::string suit;

public:
    Card() {} 
    void SetRandom();
    std::string GetName();
    std::string GetSuit();
    int GetValue();
};


