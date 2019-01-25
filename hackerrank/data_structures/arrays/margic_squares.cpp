#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printMagicSquare(int *base, int n)
{
    cout << "{";
    for (int i = 0; i < n * n; i++)
    {
        cout << base[i] << ", ";
    }
    cout << "}" << endl;
}

bool hasMagic(int *base, int n)
{
    int magicSquare[n][n];

    // create square
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            magicSquare[i][j] = base[n * i + j];
        }
    }

    int sum = n * n * (n * n + 1) / 6;
    int tempSum = 0;

    // check row sum
    for (int i = 0; i < n; i++)
    {
        tempSum = 0;
        for (int j = 0; j < n; j++)
        {
            tempSum += magicSquare[i][j];
        }

        if (tempSum != sum)
        {
            return false;
        }
    }

    //check column sum
    for (int i = 0; i < n; i++)
    {
        tempSum = 0;
        for (int j = 0; j < n; j++)
        {
            tempSum += magicSquare[j][i];
        }

        if (tempSum != sum)
        {
            return false;
        }
    }

    //front diagonal
    tempSum = 0;
    for (int i = 0; i < n; i++)
    {
        tempSum += magicSquare[i][i];
    }
    if (tempSum != sum)
    {
        return false;
    }

    //back diagonal
    tempSum = 0;
    for (int i = 0; i < n; i++)
    {
        tempSum += magicSquare[i][n - 1 - i];
    }
    if (tempSum != sum)
    {
        return false;
    }

    return true;
}

void getMagicSquares(int n)
{
    int base[n * n];

    for (int i = 0; i < n * n; i++)
    {
        base[i] = i + 1;
    }

    sort(base, base + n * n);

    do
    {
        bool isMagic = hasMagic(base, n);

        if (isMagic)
        {
            printMagicSquare(base, n);
        }
    } while (next_permutation(base, base + n * n));
}

int main(void)
{
    int n = 3;
    getMagicSquares(n);

    return 0;
}