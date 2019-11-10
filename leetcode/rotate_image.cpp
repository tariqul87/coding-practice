#include "array.cpp"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int size = n;
        n = n/2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                vector<int> temp = {matrix[i][j], matrix[j][size - 1 - i], matrix[size - 1 - i][size - 1 - j], matrix[size - 1 - j][i]};
                matrix[i][j] = temp[3];
                matrix[j][size - 1 - i] = temp[0];
                matrix[size - 1 - i][size - 1 - j] = temp[1];
                matrix[size - 1 - j][i] = temp[2];
            }
        }
    }
};

int main(void)
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    solution.rotate(matrix);
    printDoubleIntArray(matrix, " ");

    return 0;
}