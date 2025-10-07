#include <iostream>
using namespace std;

int recursiveArraySum(int *arr[], int sizes[], int dim)
{

    if (dim == 0)
    {
        int sum = 0;
        for (int i = 0; i < sizes[dim]; i++)
        {
            sum += *(arr[i]);
        }
        return sum;
    }

    int totalSum = 0;

    for (int i = 0; i < sizes[dim]; i++)
    {
        totalSum += recursiveArraySum(reinterpret_cast<int **>(arr[i]), sizes, dim - 1);
    }

    return totalSum;
}

int main()
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {6, 7, 8, 9};

    int *arr[] = {arr1, arr2, arr3};

    int sizes[] = {3, 2, 4};

    int sum = recursiveArraySum(arr, sizes, 2);

    cout << "Sum of elements in the jagged array: " << sum << endl;

    return 0;
}
