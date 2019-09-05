#include <bits/stdc++.h>
#include "./template.cpp"
using namespace std;

class Solution
{
public:
    bool lowPair(vector<int> A, vector<int> B)
    {
        return A[1] <= B[1];
    }
    bool intersects(vector<int> A, vector<int> B)
    {
        if (A.size() && B.size())
        {
            int minVal = min(A[0], B[0]);
            int maxVal = max(A[1], B[1]);

            return max(A[0], B[0]) <= min(A[1], B[1]);
        }

        return false;
    }
    vector<int> getIntersectionPair(vector<int> A, vector<int> B)
    {
        return {max(A[0], B[0]), min(A[1], B[1])};
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> result;
        while (A.size() && B.size())
        {
            vector<int> intersection;
            if (intersects(A[0], B[0]))
            {
                intersection = getIntersectionPair(A[0], B[0]);
                int size = result.size();
                if (size && result[size - 1][1] == intersection[0])
                {
                    result[size - 1][1] = intersection[1];
                }
                else
                {
                    result.push_back(intersection);
                }
            }

            if (lowPair(A[0], B[0]))
            {
                A.erase(A.begin());
            }
            else
            {
                B.erase(B.begin());
            }
        }

        return result;
    }
};

int main(void)
{
    vector<vector<int>> A = {{0, 2}, {5, 10}, {13, 23}, {24, 25}}, B = {{100, 101}};
    Solution solution;
    vector<vector<int>> result = solution.intervalIntersection(A, B);
    printDoubleIntArray(result, " ");

    return 0;
}