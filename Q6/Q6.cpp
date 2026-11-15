#include <iostream>
using namespace std;

int main()
{
    int matrix[10][10];
    int sparse[100][3];

    int rows, cols;
    int k = 1;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Store matrix dimensions
    sparse[0][0] = rows;
    sparse[0][1] = cols;

    int count = 0;

    // Convert to sparse representation
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];

                k++;
                count++;
            }
        }
    }

    sparse[0][2] = count;

    // Display sparse matrix
    cout << "\nSparse Matrix Representation:\n";
    cout << "Row\tColumn\tValue\n";

    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}