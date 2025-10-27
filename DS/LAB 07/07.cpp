#include <iostream>
#include <cstdlib>
using namespace std;
int comparisons = 0;
int partitionFirst(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l + 1;
    for (int j = l + 1; j <= r; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[l], arr[i - 1]);
    return i - 1;
}
int partitionRandom(int arr[], int l, int r)
{
    int random = l + rand() % (r - l + 1);
    swap(arr[random], arr[r]);
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
int partitionMiddle(int arr[], int l, int r)
{
    int mid = (l + r) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[r]);
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(int arr[], int l, int r, int mode)
{
    if (l < r)
    {
        int pi;
        if (mode == 1)
            pi = partitionFirst(arr, l, r);
        else if (mode == 2)
            pi = partitionRandom(arr, l, r);
        else
            pi = partitionMiddle(arr, l, r);
        quickSort(arr, l, pi - 1, mode);
        quickSort(arr, pi + 1, r, mode);
    }
}
int main()
{
    int arr[] = {9, 4, 6, 2, 8, 1, 3, 5, 7};
    int n = 9;
    comparisons = 0;
    quickSort(arr, 0, n - 1, 1);
    cout << "First pivot comparisons: " << comparisons << endl;
    comparisons = 0;
    quickSort(arr, 0, n - 1, 2);
    cout << "Random pivot comparisons: " << comparisons << endl;
    comparisons = 0;
    quickSort(arr, 0, n - 1, 3);
    cout << "Middle pivot comparisons: " << comparisons << endl;
}
