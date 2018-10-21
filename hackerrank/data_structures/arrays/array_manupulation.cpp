#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    unsigned long int n, m, max = 0;
    cin >> n >> m;

    vector<unsigned long int> arr(n + 1, 0);

    for (unsigned long int i = 0; i < m; i++)
    {
        unsigned long int a, b, x;
        cin >> a >> b >> x;
        arr[a] += x;
        if (b + 1 <= n)
        {
            arr[b + 1] -= x;
        }
    }

    unsigned long int num = 0;

    for (unsigned long int i = 1; i <= n; i++)
    {
        num += arr[i];
        if (max < num)
        {
            max = num;
        }
    }

    cout << max << endl;
}