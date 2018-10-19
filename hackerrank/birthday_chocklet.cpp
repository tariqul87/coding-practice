#include <iostream>
#include <vector>
using namespace std;

// https://www.hackerrank.com/challenges/the-birthday-bar/problem?h_r=next-challenge&h_v=zen

int main(void)
{
    vector<int> a;
    int n, d, m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int count = 0;
    cin >> d >> m;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n && j < i + m; j++)
        {
            sum += a[j];
        }

        if (sum == d)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}