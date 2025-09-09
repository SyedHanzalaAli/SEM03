#include <iostream>
using namespace std;

class DynamicMatrix
{
    int rows, cols;
    int **matrix;

public:
    DynamicMatrix(int r, int c, int val = 0)
    {
        rows = r;
        cols = c;
        allocateMatrix(val);
    }
    void allocateMatrix(int val)
    {
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = val;
            }
        }
    }
    ~DynamicMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete matrix[i];
        }
        delete matrix;
    }
    void printMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int n = matrix[i][j];
                if ((i * cols + j) % 2 == 1)
                    n += 2;
                cout << n << " ";
            }
            cout << endl;
        }
    }
    void resize(int newRows, int newCols, int val = 0)
    {
        int **newMatrix = new int *[newRows];
        for (int i = 0; i < newRows; i++)
        {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; j++)
            {
                if (i < rows && j < cols)
                {
                    newMatrix[i][j] = matrix[i][j];
                }
                else
                {
                    newMatrix[i][j] = val;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete matrix[i];
        }
        delete matrix;
        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }
    void transpose()
    {
        int **newMatrix = new int *[cols];
        for (int i = 0; i < cols; i++)
        {
            newMatrix[i] = new int[rows];
            for (int j = 0; j < rows; j++)
            {
                newMatrix[i][j] = matrix[j][i];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete matrix[i];
        }
        delete matrix;
        int temp = rows;
        matrix = newMatrix;
        rows = cols;
        cols = temp;

        matrix = newMatrix;
    }
    void inputMatrix()
    {
        cout << "Enter elements :  " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }
};

int main()
{
    DynamicMatrix mat(2, 3);
    mat.inputMatrix();
    mat.printMatrix();

    mat.resize(3, 4, 0);
    mat.printMatrix();

    mat.transpose();
    mat.printMatrix();

    return 0;
}