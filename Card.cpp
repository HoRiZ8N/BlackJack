#include "Card.h"
#include <cstdlib>
#include <ctime>

std::string Card::GetName() const { return name; }

std::string Card::GetSuit() const { return suit; }

int Card::GetValue() const { return value; }

Card::Card(){}

void Card::SetRandom()
{
    static bool seedSet = false;
    if (!seedSet) {
        srand(static_cast<unsigned int>(time(0)));
        seedSet = true;
    }
    
    int randomVal = rand() % 13 + 1;
    value = (randomVal <= 10) ? randomVal : 10;

    switch (randomVal) {
        case 1: name = "Ace"; break;
        case 11: name = "Jack"; break;
        case 12: name = "Queen"; break;
        case 13: name = "King"; break;
        default: name = std::to_string(randomVal);
    }

    int randomSuit = rand() % 4;
    switch (randomSuit) {
        case 0: suit = "Diamonds"; break;
        case 1: suit = "Clubs"; break;
        case 2: suit = "Hearts"; break;
        case 3: suit = "Spades"; break;
    }
}
