#include "Card.h"

std::string Card::GetName() { return name; }

std::string Card::GetSuit() { return suit; }

int Card::GetValue() { return value;}

void Card::SetRandom()
{
    srand(time(0));
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