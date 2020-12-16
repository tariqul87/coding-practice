#include "array.cpp"

class Solution
{
public:
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 1)
        {
            return false;
        }

        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (n == 1)
        {
            return grid[0][0] == 0 ? 1 : -1;
        }

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }
        deque<pair<pair<int, int>, int>> nodes;
        nodes.push_back(make_pair(make_pair(0, 0), 1));
        grid[0][0] = 1;

        while (nodes.size())
        {
            int i = nodes.front().first.first;
            int j = nodes.front().first.second;
            int d = nodes.front().second;

            for (vector<int> dir : dirs)
            {
                int x = i + dir[0];
                int y = j + dir[1];

                if (isValid(grid, x, y))
                {
                    if (x == n - 1 && y == n - 1)
                    {
                        return d + 1;
                    }

                    grid[x][y] = 1;
                    nodes.push_back(make_pair(make_pair(x, y), d + 1));
                }
            }

            nodes.pop_front();
        }

        return -1;
    }
};