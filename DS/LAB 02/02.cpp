#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int students = 5, subjects = 4;

    int **marks = new int *[students];
    for (int i = 0; i < students; i++)
    {
        marks[i] = new int[subjects];
    }
    cout << "enter marks : " << endl;
    for (int i = 0; i < students; i++)
    {
        cout << "student " << i + 1 << endl;
        for (int j = 0; j < subjects; j++)
        {
            cout << "subject " << j + 1 << endl;
            cin >> marks[i][j];
        }
    }

    int *total = new int[students];
    int topperIndex = 0, highest = 0;
    cout << "total marks of each student : " << endl;
    for (int i = 0; i < students; i++)
    {
        total[i] = 0;
        for (int j = 0; j < subjects; j++)
        {
            total[i] += marks[i][j];
        }
        cout << "student " << i + 1 << total[i] << endl;

        if (total[i] > highest)
        {
            highest = total[i];
            topperIndex = i;
        }
    }
    cout << "average marks of each subject : " << endl;
    for (int j = 0; j < subjects; j++)
    {
        int sum = 0;
        for (int i = 0; i < students; i++)
        {
            sum += marks[i][j];
        }
        double avg = (double)sum / students;
        cout << "subject " << j + 1 << avg << endl;
    }
    cout << "topper : student" << topperIndex + 1 << " marks : " << highest << endl;

    for (int i = 0; i < students; i++)
    {
        delete marks[i];
    }
    delete marks;
    delete total;

    return 0;
}