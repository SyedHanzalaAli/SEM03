#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int rows;
    cout << "Enter number of rows in the hall ";
    cin >> rows;

    string **seatingChart = new string *[rows];
    int *seatsInRow = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cout << "enter number of seats in row " << i + 1 << ":";
        cin >> seatsInRow[i];
        seatingChart[i] = new string[seatsInRow[i]];
    }

    cout << "\n Enter attendee names (use empty if seat is free) : \n";
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < seatsInRow[i]; j++)
        {
            cout << "seat  " << j + 1 << endl;
            cin >> seatingChart[i][j];
        }
    }

    cout << "\n seating chart \n";
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << endl;
        for (int j = 0; j < seatsInRow[i]; j++)
        {
            cout << "seat  " << seatingChart[i][j] << endl;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete seatingChart[i];
    }
    delete seatingChart;
    delete seatsInRow;

    return 0;
}