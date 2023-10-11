#include <iostream>
#include <limits>
using namespace std;

int inf = numeric_limits<int>::max();

void display(int mat[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int red_row(int mat[][10], int n)
{
    int mini[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int minn = INT16_MAX;
        for (int j = 0; j < n; j++)
        {
            minn = min(minn, mat[i][j]);
        }
        mini[i] = minn;
        for (int j = 0; j < n; j++)
        {
            mat[i][j] -= mini[i];
        }
        sum += mini[i];
    }
    return sum;
}

int red_col(int mat[][10], int n)
{
    int row = red_row(mat, n);
    int mini[n];
    int col = 0;

    for (int i = 0; i < n; i++)
    {
        int minn = INT16_MAX;
        for (int j = 0; j < n; j++)
        {
            minn = min(minn, mat[j][i]);
        }
        mini[i] = minn;
        for (int j = 0; j < n; j++)
        {
            mat[j][i] -= mini[i];
        }
        col += mini[i];
    }
    return col + row;
}

int main()
{
    int n = 5;
    int matrix[10][10] = {{inf, 20, 30, 10, 11},
                          {15, inf, 16, 4, 2},
                          {3, 5, inf, 2, 4},
                          {19, 6, 18, inf, 3},
                          {16, 4, 7, 16, inf}};
    cout << red_col(matrix, n) << endl;
    display(matrix, n);
    return 0;
}
