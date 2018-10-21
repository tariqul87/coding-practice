#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<vector<int>> a(6, vector<int>(6, 0));
    int max = -10000;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            int sum = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
            if (sum > max)
            {
                max = sum;
            }
        }
    }

    cout << max << endl;
    return 0;
}