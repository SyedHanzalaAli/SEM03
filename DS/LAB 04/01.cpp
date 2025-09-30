#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}

int main()
{
    int arr[10];

    cout << "enter 10 elements : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, 10);

    cout << "minimum 4 elements :  " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}