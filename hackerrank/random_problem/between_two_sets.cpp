#include <iostream>
#include <vector>
using namespace std;

// https://www.hackerrank.com/challenges/between-two-sets/problem

int calculateGCD(int a, int b)
{
    int max = a > b ? a : b;
    int min = a <= b ? a : b;

    while (max % min != 0)
    {
        int d = max - min;
        if (d > min)
        {
            max = d;
        }
        else
        {
            max = min;
            min = d;
        }
    }

    return min;
}

int calculatelcm(int m, int n)
{
    return (m * n) / calculateGCD(m, n);
}

int checkIfCommonFactor(vector<int> a, int n)
{
    bool common = true;

    for (auto iterator = a.begin(); iterator != a.end(); iterator++)
    {
        if (*iterator % n != 0)
        {
            common = false;
            break;
        }
    }

    return common;
}

int main(void)
{
    int m, n, lcm = 1, gcd, mina = 101, maxb = 0;

    cin >> m >> n;
    vector<int> a, b;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        if (x < mina)
        {
            mina = x;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
        if (x > maxb)
        {
            maxb = x;
        }
    }

    if (mina > maxb)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        lcm = calculatelcm(lcm, a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            gcd = b[i];
        }
        else
        {
            gcd = calculateGCD(gcd, b[i]);
        }
    }

    int count = 0;

    for (int i = 1; lcm * i <= gcd; i++)
    {
        if (gcd % (lcm * i) == 0)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}