#include <iostream>
using namespace std;
class Product
{
public:
    string name, desc;
    float price;
    bool available;
};
int partition(Product arr[], int l, int r)
{
    float pivot = arr[r].price;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j].price < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(Product arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
int main()
{
    Product arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i].name >> arr[i].price >> arr[i].desc >> arr[i].available;
    quickSort(arr, 0, 2);
    for (int i = 0; i < 3; i++)
        cout << arr[i].name << " " << arr[i].price << " " << arr[i].desc << " " << arr[i].available << endl;
}
