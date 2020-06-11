#include "array.cpp"

class Solution
{
public:
    bool isValidMountain(vector<int> &A, int i, int j)
    {
        if (j - i + 1 < 3)
        {
            return false;
        }

        if (A[j - 1] <= A[j])
        {
            return false;
        }

        return true;
    }
    int getMountainEnd(vector<int> &A, int i)
    {
        int j = i + 1;
        while (j < A.size() && A[j - 1] < A[j])
        {
            j++;
        }

        while (j < A.size() && A[j - 1] > A[j])
        {
            j++;
        }

        return j - 1;
    }
    int longestMountain(vector<int> &A)
    {
        int result = 0, i = 0;

        while (i < A.size())
        {
            if (i + 1 < A.size() && A[i] >= A[i + 1])
            {
                i++;
            }
            else
            {
                int j = getMountainEnd(A, i);

                if (isValidMountain(A, i, j))
                {
                    result = max(result, j - i + 1);
                }
                i = i == j ? i + 1 : j;
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> arr = {-1, 0, 1, 2, 3, 4, 5, 6, 4, 5, 6, 7, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Solution s;
    cout << s.longestMountain(arr) << endl;

    return 0;
}