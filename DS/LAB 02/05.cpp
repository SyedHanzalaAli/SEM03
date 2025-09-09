#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<vector<double>> gpas = {
        {3.1, 3.5, 3.8},
        {2.9, 3.2, 3.6, 3.9},
        {3.4, 3.7},
        {3.3}};
    string department[] = {"SE", "AI", "DS", "CS"};

    cout << "1st semester core courses GPAs : \n";
    for (int i = 0; i < gpas.size(); i++)
    {
        cout << department[i] << " courses : " << gpas[i].size() << endl;
        for (int j = 0; j < gpas[i].size(); j++)
        {
            cout << gpas[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}