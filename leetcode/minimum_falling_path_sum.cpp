#include "./array.cpp"

class Solution
{
public:
    int sum[100][100];
    int minFallingPathSum(vector<vector<int>> &A)
    {
        int size = A.size();
        for (int j = 0; j < size; j++)
        {
            sum[size - 1][j] = A[size - 1][j];
        }

        for (int i = size - 2; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (j == 0)
                {
                    sum[i][j] = min(sum[i + 1][j], sum[i + 1][j + 1]);
                }
                else if (j == size - 1)
                {
                    sum[i][j] = min(sum[i + 1][j - 1], sum[i + 1][j]);
                }
                else
                {
                    sum[i][j] = min(sum[i + 1][j - 1], min(sum[i+1][j], sum[i + 1][j + 1]));
                }

                sum[i][j] += A[i][j];
            }
        }

        int result = sum[0][0];

        for (int j = 1; j < size; j++)
        {
            if (sum[0][j] < result)
            {
                result = sum[0][j];
            }
        }

        return result;
    }
};

int main(void)
{
    vector<vector<int>> arr = {{-84,-36,2},{87,-79,10},{42,10,63}};
    Solution solution;
    cout << solution.minFallingPathSum(arr) << endl;
    return 0;
}