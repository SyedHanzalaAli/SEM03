#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber()
{
    return rand() % 100 + 1;
}

void guessNumber(int target, int turn, int playerCount)
{
    int guess;
    cout << "player" << turn << " , guess number : " << endl;
    cin >> guess;

    if (guess == target)
    {
        cout << "correct guess by player :" << turn << endl;
        return;
    }

    if (guess < target)
    {
        cout << "guess is low \n";
    }
    else
    {
        cout << "guess is high \n";
    }

    turn = (turn % playerCount) + 1;

    guessNumber(target, turn, playerCount);
}

int main()
{
    srand(time(0));

    int target = generateRandomNumber();
    int playerCount = 2;

    guessNumber(target, 1, playerCount);

    return 0;
}