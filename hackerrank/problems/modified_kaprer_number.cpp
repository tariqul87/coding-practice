#include <bits/stdc++.h>
using namespace std;

#include <math.h>

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q)
{
    vector<int> result;

    for (int i = p; i <= q; i++)
    {
        int d = 0;
        int n = i;
        while (n)
        {
            n = n / 10;
            d++;
        }

        n = i * i;
        int divider = pow(10, d);
        int r = n % divider;
        int l = n / divider;

        if (r + l == i)
        {
            result.push_back(i);
        }
    }

    if (!result.size())
    {
        cout << "INVALID RANGE" << endl;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
