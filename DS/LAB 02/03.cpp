#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student
{
    int marks[5];

public:
    void inputMarks(int id)
    {
        cout << "enter marks for student : " << id + 1 << "5 subjects" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "subjects " << i + 1 << ":";
            cin >> marks[i];
        }
    }
    int getTotalMarks() const
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += marks[i];
        }
    }
};

class Department
{
    vector<Student> students;

public:
    void inputDepart(int deptid)
    {
        int n;
        cout << "enter number of students in department : " << deptid << endl;
        cin >> n;
        students.resize(n);
        for (int i = 0; i < n; i++)
        {
            students[i].inputMarks(i);
        }
    }
    void calStats(int deptid)
    {
        if (students.empty())
        {
            cout << "no students" << endl;
            return;
        }
        int high = -1e9, low = 1e9, sum = 0;
        for (auto &s : students)
        {
            int total = s.getTotalMarks();
            high = max(high, total);
            low = min(low, total);
            sum += total;
        }
        double avg = (double)sum / students.size();

        cout << "\n Department " << deptid + 1 << "results \n";
        cout << "Highest marks " << high << endl;
        cout << "lowest marks " << low << endl;
        cout << "average marks " << avg << endl;
    }
};

class University
{
    vector<Department> departments;

public:
    void inputData()
    {
        int n;
        cout << "enter number of  departments : " << endl;
        cin >> n;
        departments.resize(n);
        for (int i = 0; i < n; i++)
        {
            departments[i].inputDepart(i);
        }
    }
    void displayResults()
    {
        for (int i = 0; i < departments.size(); i++)
        {
            departments[i].calStats(i);
        }
    }
};

int main()
{
    University u;
    u.inputData();
    u.displayResults();

    return 0;
}