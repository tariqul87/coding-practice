#include "./array.cpp"

class Solution
{
public:
    int getGridArea(int i, int j, vector<vector<int>> &grid)
    {
        int row = grid.size(), column = grid[0].size();

        if (0 <= i && i < row && 0 <= j && j < column && grid[i][j])
        {
            grid[i][j] = 0;
            return 1 + getGridArea(i - 1, j, grid) + getGridArea(i, j - 1, grid) + getGridArea(i, j + 1, grid) + getGridArea(i + 1, j, grid);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size(), column = grid[0].size(), maxArea = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                int currentArea = getGridArea(i, j, grid);
                maxArea = max(currentArea, maxArea);
            }
        }

        return maxArea;
    }
};

int main(void)
{
    Solution solution;
    // vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
    //                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    //                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    vector<vector<int>> grid;
    for (int i = 0; i < 5; i++)
    {
        vector<int> row;
        for (int j = 0; j < 5; j++)
        {
            row.push_back(1);
        }
        grid.push_back(row);
    }

    cout << solution.maxAreaOfIsland(grid) << endl;
}