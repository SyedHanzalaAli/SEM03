#include <iostream>
#include <cstring>
using namespace std;

class Exam{
    char* studentName;
    char* examDate;
    int score;

public:
    Exam(){
        studentName = nullptr;
        examDate = nullptr;
        score =0;
    }
    Exam(const char* name , const char* date , int s){
        studentName = new char[strlen(name)+1];
        strcpy(studentName,name);

        examDate = new char[strlen(date)+1];
        strcpy(examDate,date);

        score = s;
    }
    ~Exam(){
        delete[] studentName;
        delete[] examDate;
    }
    void display()const{
        cout << "Student :  " << (studentName ? studentName : "Not Found")
        << "Date :  " << (examDate ? examDate : "Not Found")
        << "Score " << score << endl;
    }
};

int main(){
    Exam e1("Hanzala" , "2003-07-01", 90);
    cout << "Exam Details : ";
    e1.display();

    Exam e2 = e1;

    cout << "Exam2 details : ";
    e2.display();

    return 0;
}
