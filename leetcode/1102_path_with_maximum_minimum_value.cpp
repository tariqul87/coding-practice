#include "array.cpp"

class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool invalid(int i, int j, vector<vector<int>> &A)
    {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[i].size() || A[i][j] == -1)
        {
            return true;
        }

        return false;
    }
    int maximumMinimumPath(int i, int j, vector<vector<int>> &A, int currentVal)
    {
        if (i == A.size() - 1 && j == A[i].size() - 1)
        {
            return min(A[i][j], currentVal);
        }

        if (invalid(i, j, A) || currentVal == -1)
        {
            return -1;
        }

        int val = A[i][j];

        if (val == 0) {
            return 0;
        }
        
        currentVal = min(currentVal, val);


        int result = -1;
        A[i][j] = -1;

        for (int k = 0; k < dir.size() && result < val; k++)
        {
            int i_new = i + dir[k][0];
            int j_new = j + dir[k][1];

            if (!invalid(i_new, j_new, A) && result <= A[i_new][j_new])
            {
                result = max(result, maximumMinimumPath(i + dir[k][0], j + dir[k][1], A, currentVal));
            }
        }

        A[i][j] = val;
        cout<<i<<","<<j<<": "<<result<<endl;
        return result;
    }
    int maximumMinimumPath(vector<vector<int>> &A)
    {
        return maximumMinimumPath(0, 0, A, INT_MAX);
    }
};

int main(void)
{
    vector<vector<int>> A = {{0,1,0,1,3,1,3},{0,0,3,0,2,3,3},{0,3,0,3,2,1,3},{0,3,1,0,3,3,0},{0,1,2,3,2,3,3},{0,3,2,1,2,3,0}};
    Solution s;
    cout<<s.maximumMinimumPath(A)<<endl;
    return 0;
}