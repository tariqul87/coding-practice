#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> array, int start, int length, int element)
{
    for (int i = start; i < array.size() && i < length; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }

    return false;
}

vector<int> get_stone_numbers(int n, int a, int b)
{
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        result.push_back(i * a + (n - i - 1) * b);
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}

int main(void)
{
    int t, n, a, b;
    vector<vector<int>> result;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> a;
        cin >> b;
        vector<int> current_result;
        current_result = get_stone_numbers(n, a, b);
        result.push_back(current_result);
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
    return 0;
}