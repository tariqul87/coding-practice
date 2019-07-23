#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i][0] == 0)
            {
                for (int j = 0; j < A[i].size(); j++)
                {
                    A[i][j] = A[i][j] == 0 ? 1 : 0;
                }
            }
        }

        int answer = 0;
        for (int j = 0; j < A[0].size(); j++)
        {
            int countZero = 0;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i][j] == 0)
                {
                    countZero++;
                }
            }

            int maxCount = A.size() - countZero > countZero ? A.size() - countZero : countZero;
            answer += maxCount * pow(2, A[0].size() - j - 1);
        }

        return answer;
    }
};

int main(void)
{
    vector<vector<int>> matrix = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    Solution solution;
    cout << solution.matrixScore(matrix) << endl;

    return 0;
}