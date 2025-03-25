#include <iostream>
#include <vector>
using namespace std;

class Guesser
{
public:
  int takeGuesserInput()
  {
    int guessednum;
    cout << "\nGuesser, enter your number: ";
    cin >> guessednum;
    return guessednum;
  }
};

class Player
{
public:
  int takePlayerInput(int playerID)
  {
    int playernum;
    cout << "Player " << playerID << ", enter your guessed number: ";
    cin >> playernum;
    return playernum;
  }
};

class Umpire
{
  int guessedNumber;
  vector<int> playerNumbers;

public:
  void getNumberFromGuesser()
  {
    Guesser g;
    guessedNumber = g.takeGuesserInput();
    cout << "Number guessed by the Guesser: " << guessedNumber << endl;
  }

  void getNumberFromPlayers(int numPlayers)
  {
    Player p;
    playerNumbers.resize(numPlayers);
    for (int i = 0; i < numPlayers; i++)
    {
      playerNumbers[i] = p.takePlayerInput(i + 1);
    }
  }

  void printResult()
  {
    vector<int> winners;
    for (int i = 0; i < playerNumbers.size(); i++)
    {
      if (playerNumbers[i] == guessedNumber)
      {
        winners.push_back(i + 1);
      }
    }

    if (winners.empty())
    {
      cout << "No one guessed the number correctly!" << endl;
    }
    else
    {
      cout << " Winners: ";
      for (int winner : winners)
      {
        cout << "Player " << winner << " ";
      }
      cout << "guessed the correct number! \n";
    }
  }
};

int main()
{
  char playAgain;

  do
  {
    int numPlayers;
    cout << "\nEnter the number of players: ";
    while (!(cin >> numPlayers) || numPlayers <= 0)
    {
      cout << "Invalid input! Please enter a valid number of players: ";
      cin.clear();
      cin.ignore(1000, '\n');
    }

    Umpire u;
    u.getNumberFromGuesser();
    u.getNumberFromPlayers(numPlayers);
    u.printResult();

    cout << "\nDo you want to play again? (y/n): ";
    cin >> playAgain;
    cin.ignore();

  } while (playAgain == 'y' || playAgain == 'Y');

  cout << "Thanks for playing! \n";
  return 0;
}
