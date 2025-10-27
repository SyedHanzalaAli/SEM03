#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int getMax(vector<int> &arr)
{
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int> &arr)
{
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main()
{
    vector<int> arr1 = {5, 2, 8, 1, 9, 4, 3, 7, 6, 0};
    vector<int> arr2 = {15, 12, 18, 11, 19, 14, 13, 17, 16, 10};
    vector<int> arr(20);
    for (int i = 0; i < 10; i++)
        arr[i] = arr1[i];
    for (int i = 0; i < 10; i++)
        arr[i + 10] = arr2[i];
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    radixSort(arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
