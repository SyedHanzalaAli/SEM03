#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int startIndex)
{
    for (int i = startIndex + 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= startIndex && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
void rearrangeArray(int arr[], int n)
{

    insertionSort(arr, n, 0);

    int middle = n / 2;
    int maxIndex = n - 1;

    swap(arr[middle], arr[maxIndex]);

    insertionSort(arr, n, middle + 1);
}

int main()
{
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};

    rearrangeArray(arr, 9);

    cout << "Rearranged array with the maximum element at the middle:" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
