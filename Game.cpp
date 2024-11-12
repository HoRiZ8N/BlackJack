#include "Game.h"

void Game::DrawCardPlayer(int &score)
{
    Card card;
    card.SetRandom();
    score += card.GetValue();
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    std::cout << "Player drew " << card.GetName() << " of " << card.GetSuit()
              << " (Value: " << card.GetValue() << ")\n";
}

void Game::DrawCardDealer(int &score)
{
    Card card;
    card.SetRandom();
    score += card.GetValue();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Dealer drew " << card.GetName() << " of " << card.GetSuit()
              << " (Value: " << card.GetValue() << ")\n";
}

void Game::ShowPlayerScore()
{
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    std::cout << "Player's total score: " << PlayerScore << "\n\n";
}

void Game::ShowDealerScore()
{
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    std::cout << "Dealer's total score: " << DealerScore << "\n\n";
}

void Game::GameLoop()
{
    PlayerScore = 0;
    DealerScore = 0;

    std::cout << "\nStarting Blackjack game...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); 

    std::cout << "\nPlayer's starting hand:\n";
    DrawCardPlayer(PlayerScore);
    DrawCardPlayer(PlayerScore);
    ShowPlayerScore();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nDealer's starting hand:\n";
    DrawCardDealer(DealerScore);
    DrawCardDealer(DealerScore);
    ShowDealerScore();

    while (PlayerScore < 21) 
    {
        std::cout << "To draw a card, type 'd'. To stay, type 's': ";
        char input;
        std::cin >> input;
        if (input == 'd' || input == 'D')
        {
            DrawCardPlayer(PlayerScore);
            ShowPlayerScore();
            if (PlayerScore > 21) {
                std::cout << "Player busts! You've lost.\n";
                return;
            }
        }
        else if (input == 's' || input == 'S')
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Please type 'd' or 's'.\n";
        }
    }

    std::cout << "\nDealer's turn...\n";
    while (DealerScore < PlayerScore)
    {
        DrawCardDealer(DealerScore);
        ShowDealerScore();
    }

    ShowFinalResults();
}

void Game::ShowFinalResults()
{
    ShowPlayerScore();
    ShowDealerScore();
    if (DealerScore > 21)
    {
        std::cout << "Dealer busts! Player wins.\n";
    }
    else if (PlayerScore > DealerScore)
    {
        std::cout << "Player wins!\n";
    }
    else if (DealerScore > PlayerScore)
    {
        std::cout << "Dealer wins.\n";
    }
    else
    {
        std::cout << "It's a tie!\n";
    }

    std::cout << "\nEnter any key to exit: ";
    char c;
    std::cin >> c;
}
