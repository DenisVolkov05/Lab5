#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, n, m;

    cout << "введи число уравнений: ";
    cin >> n;
    cout << "введи число неизвестных: ";
    cin >> m;
    m += 1;
    float** matrix = new float* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];


    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cout << "Элемент " << "[" << i + 1 << " , " << j + 1 << "]: ";
            cin >> matrix[i][j];
        }


    float  tmp, *xx = new float[m];
    int k;

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }

    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }

    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
}