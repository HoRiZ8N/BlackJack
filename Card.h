#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

class Card
{
private:
    std::string name;
    int value;
    std::string suit;

public:
    Card();
    void SetRandom();
    std::string GetName() const;
    std::string GetSuit() const;
    int GetValue() const;
};
