#include <bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int> &array, int target)
{
    vector<int> result;
    vector<int> sorted;

    for (int i = 0; i < array.size(); i++)
    {
        sorted.push_back(array[i]);
    }

    sort(sorted.begin(), sorted.end());
    int i = 0, j = sorted.size() - 1;

    while (sorted[i] + sorted[j] != target && i <= j)
    {
        if (sorted[i] + sorted[j] < target)
        {
            i++;
        }
        else if (sorted[i] + sorted[j] > target)
        {
            j--;
        }
    }

    for (int x = 0; x < array.size(); x++)
    {
        if (sorted[i] == array[x] || sorted[j] == array[x])
        {
            result.push_back(x);
        }
    }

    return result;
}

int main(void)
{
    int n, target;
    vector<int> array;
    cin >> n;
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }

    vector<int> result;
    result = two_sum(array, target);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}