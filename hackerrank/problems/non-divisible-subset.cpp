#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubet(vector<int> arr, int k)
{
    int reminders[1000], count = 0;
    memset(reminders, 0, 1000 * sizeof(int));

    for (int i = 0; i < arr.size(); i++)
    {
        reminders[arr[i] % k]++;
    }

    for (int i = 1; i <= k / 2; i++)
    {
        count += (i == k - i) ? 1 : max(reminders[i], reminders[k - i]);
    }

    if (reminders[0])
    {
        count++;
    }

    return count;
}

int main(void)
{
    int n, k, m;
    cin >> n >> k;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        arr.push_back(m);
    }

    cout << nonDivisibleSubet(arr, k) << endl;
    return 0;
}