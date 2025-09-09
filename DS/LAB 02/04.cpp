#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    bool friends[5][5] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 0}};

    auto hasCommonFriend = [&](int a, int b)
    {
        for (int i = 0; i < 5; i++)
        {
            if (friends[a][i] && friends[b][i])
            {
                return true;
            }
        }
        return false;
    };

    return 0;
}