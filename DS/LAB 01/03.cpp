#include <iostream>
using namespace std;

class Box
{
    int *value;

public:
    Box(int v = 0)
    {
        value = new int(v);
        cout << "constructor called . Value = " << *value << endl;
    }
    ~Box()
    {
        cout << "destructor called deleting Value = " << *value << endl;
        delete value;
    }
    Box &operator=(const Box &other)
    {
        if (this == &other)
            return *this;

        delete value;
        value = new int(*(other.value));
        cout << "Copy assignment called . Copied Value = " << *value << endl;
        return *this;
    }
    void setValue(int v){
        *value =v;
    }
    int getValue()const{
        return *value;
    }
};

int main(){
    cout << "Deep Copy" <<endl;
    Box b1(10);
    Box b2 = b1;
    b2.setValue(20);

    cout << "b1 value = " << b1.getValue() <<endl;
    cout << "b2 value = " << b2.getValue() <<endl;

    cout << "Assignment"<<endl;
    Box b3(30);
    b3 = b1;
    b3.setValue(40);

    cout << "b1 value = " << b1.getValue() <<endl;
    cout << "b3 value = " << b3.getValue() <<endl;

    cout << "Shallow Copy" << endl;
    Box b4(50);
    Box b5 = b4;

    Box b6(60);
    b6=b4;

    return 0;

}

