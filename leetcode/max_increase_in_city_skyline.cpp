#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        vector<int> row(grid.size(), -1), column(grid[0].size(), -1);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (row[i] < grid[i][j])
                {
                    row[i] = grid[i][j];
                }

                if (column[j] < grid[i][j])
                {
                    column[j] = grid[i][j];
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                sum += abs(grid[i][j] - min(row[i], column[j]));
            }
        }

        return sum;
    }
};
/*
4 4 
3 0 8 4
2 4 5 7
9 2 6 3
0 3 1 0
*/

int main(void)
{
    int n, m;
    vector<vector<int>> grid;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }

        grid.push_back(row);
    }

    Solution solution;
    cout << solution.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}