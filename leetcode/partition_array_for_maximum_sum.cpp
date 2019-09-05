#include <bits/stdc++.h>
#include "./template.cpp"
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &A, int K)
    {
        int sum[A.size() + 1];
        memset(sum, 0, sizeof(int) * (A.size() + 1));
        for (int i = A.size() - 1; i >= 0; i--)
        {
            int maxVal = A[i];
            sum[i] = A[i] + sum[i + 1];
            for (int j = 1; j < K && i + j < A.size(); j++)
            {
                maxVal = max(maxVal, A[i + j]);
                sum[i] = max(sum[i], maxVal * (j + 1) + sum[i + j + 1]);
            }
        }

        return sum[0];
    }
};

int main(void)
{
    vector<int> A = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    Solution solution;
    cout << solution.maxSumAfterPartitioning(A, 4) << endl;
    return 0;
}