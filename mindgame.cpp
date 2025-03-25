#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Guesser
{
public:
  int takeGuesserInput(int lowerLimit, int upperLimit, bool randomMode)
  {
    int guessednum;
    if (randomMode)
    {
      guessednum = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
      cout << "\nGuesser (Computer) has selected a number!" << endl;
    }
    else
    {
      cout << "\nGuesser, enter a number between " << lowerLimit << " and " << upperLimit << ": ";
      cin >> guessednum;
      while (guessednum < lowerLimit || guessednum > upperLimit)
      {
        cout << "Invalid input! Enter a number within the range: ";
        cin >> guessednum;
      }
    }
    return guessednum;
  }
};

class Player
{
public:
  int takePlayerInput(int playerID, int lowerLimit, int upperLimit)
  {
    int playernum;
    cout << "Player " << playerID << ", enter your guessed number: ";
    cin >> playernum;
    while (playernum < lowerLimit || playernum > upperLimit)
    {
      cout << "Invalid input! Enter a number within the range: ";
      cin >> playernum;
    }
    return playernum;
  }
};

class Umpire
{
  int guessedNumber;
  vector<int> playerNumbers;
  vector<int> scores;

public:
  Umpire(int numPlayers)
  {
    scores.resize(numPlayers, 0);
  }

  void getNumberFromGuesser(int lowerLimit, int upperLimit, bool randomMode)
  {
    Guesser g;
    guessedNumber = g.takeGuesserInput(lowerLimit, upperLimit, randomMode);
  }

  void getNumberFromPlayers(int numPlayers, int lowerLimit, int upperLimit)
  {
    Player p;
    playerNumbers.resize(numPlayers);
    for (int i = 0; i < numPlayers; i++)
    {
      playerNumbers[i] = p.takePlayerInput(i + 1, lowerLimit, upperLimit);
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
        scores[i]++;
      }
    }

    if (winners.empty())
    {
      cout << "No one guessed the number correctly.\n";
      giveHint();
    }
    else
    {
      cout << "Winners: ";
      for (int winner : winners)
      {
        cout << "Player " << winner << " ";
      }
      cout << "guessed the correct number!\n";
    }
  }

  void giveHint()
  {
    int closestDiff = abs(playerNumbers[0] - guessedNumber);
    int closestPlayer = 1;

    for (int i = 1; i < playerNumbers.size(); i++)
    {
      int diff = abs(playerNumbers[i] - guessedNumber);
      if (diff < closestDiff)
      {
        closestDiff = diff;
        closestPlayer = i + 1;
      }
    }

    cout << "Hint: The closest guess was by Player " << closestPlayer << ". Try again.\n";
  }

  void displayScores()
  {
    cout << "\nScoreboard:\n";
    for (int i = 0; i < scores.size(); i++)
    {
      cout << "Player " << i + 1 << ": " << scores[i] << " wins\n";
    }
  }
};

int main()
{
  srand(time(0));
  char playAgain;
  int numPlayers, lowerLimit, upperLimit;
  bool randomMode;

  cout << "Welcome to the Number Guessing Game.\n";

  cout << "Enter the number of players: ";
  while (!(cin >> numPlayers) || numPlayers <= 0)
  {
    cout << "Invalid input! Enter a valid number of players: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }

  cout << "\nSelect difficulty level:\n";
  cout << "1. Easy (1-10)\n";
  cout << "2. Medium (1-50)\n";
  cout << "3. Hard (1-100)\n";
  int choice;
  cin >> choice;

  switch (choice)
  {
  case 1:
    lowerLimit = 1, upperLimit = 10;
    break;
  case 2:
    lowerLimit = 1, upperLimit = 50;
    break;
  case 3:
    lowerLimit = 1, upperLimit = 100;
    break;
  default:
    lowerLimit = 1, upperLimit = 10;
    break;
  }

  cout << "Do you want the guesser to choose a number randomly? (y/n): ";
  char randomChoice;
  cin >> randomChoice;
  randomMode = (randomChoice == 'y' || randomChoice == 'Y');

  Umpire u(numPlayers);

  do
  {
    u.getNumberFromGuesser(lowerLimit, upperLimit, randomMode);
    u.getNumberFromPlayers(numPlayers, lowerLimit, upperLimit);
    u.printResult();
    u.displayScores();

    cout << "\nDo you want to play again? (y/n): ";
    cin >> playAgain;
    cin.ignore();

  } while (playAgain == 'y' || playAgain == 'Y');

  cout << "Thanks for playing! See you next time.\n";
  return 0;
}
