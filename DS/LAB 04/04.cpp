#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
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

bool containsDuplicates(vector<int> &arr)
{
    selectionSort(arr);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (containsDuplicates(arr))
    {
        cout << "The array contains duplicates." << endl;
    }
    else
    {
        cout << "The array does not contain duplicates." << endl;
    }

    return 0;
}
