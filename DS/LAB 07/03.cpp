#include <iostream>
#include <vector>
using namespace std;
struct Runner
{
    string name;
    int time;
};
void merge(vector<Runner> &arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<Runner> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].time <= R[j].time)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(vector<Runner> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    vector<Runner> arr(10);
    for (int i = 0; i < 10; i++)
        cin >> arr[i].name >> arr[i].time;
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 5; i++)
        cout << arr[i].name << " " << arr[i].time << endl;
    return 0;
}
