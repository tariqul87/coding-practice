#include <bits/stdc++.h>
#include "./template.cpp"
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> result;

        for (int i = A.size() - 1; i > 0; i--)
        {
            int max = A[i], index = i;
            for (int j = 0; j < i; j++)
            {
                if (A[j] > max)
                {
                    max = A[j];
                    index = j;
                }
            }

            if (max > A[i])
            {
                if (index > 0)
                {
                    result.push_back(index + 1);
                    reverse(A.begin(), A.begin() + index + 1);
                }

                result.push_back(i + 1);
                reverse(A.begin(), A.begin() + i + 1);
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> pancakes = {1, 2, 3, 1};
    Solution solution;
    printIntArray(solution.pancakeSort(pancakes), " ");
    return 0;
}