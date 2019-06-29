#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        return matrix;
    }
};

int main(void)
{
    int m, n;
    vector<vector<int>> nums;

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }

        nums.push_back(row);
    }

    Solution solution;
    vector<vector<int>> result = solution.updateMatrix(nums);

    cout << "[" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "[";
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << ", ";
        }
        cout << "]" << endl;
    }

    cout << "]" << endl;

    return 0;
}