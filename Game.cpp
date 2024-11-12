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

    while (PlayerScore < 21) // player's loop
    {
        std::cout << "To draw a card type 'd'\nTo stay type 's'\n";
        char input;
        std::cin >> input;
        if (input == 'd' || input == 'D')
        {
            DrawCardPlayer(PlayerScore);
            ShowPlayerScore();
        }
        else if (input == 's' || input == 'S')
        {
            break;
        }
        else
        {
            continue;
        }
    }

    if (PlayerScore > 21)
    {
        ShowPlayerScore();
        std::cout << "You've lost." << std::endl;
        return;
    }

    while (DealerScore < PlayerScore)
    {
        if (DealerScore > 21)
        {
            break;
        }
        DrawCardDealer(DealerScore);
        ShowDealerScore();
    }
    ShowPlayerScore();
    ShowDealerScore();
    if (DealerScore > PlayerScore && DealerScore <= 21)
    {
        std::cout << "Dealer won.";
    }
    else if (DealerScore < PlayerScore)
    {
        std::cout << "Player won.";
    }
    else
    {
        std::cout << "Tie.";
    }
    getch();
}