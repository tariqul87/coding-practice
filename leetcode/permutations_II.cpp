#include "array.cpp"

class Solution
{
public:
    void generatePermutations(vector<int> &arr, int start, vector<vector<int>> &result)
    {
        if (start >= arr.size())
        {
            result.push_back(arr);
            return;
        }
        map<int, bool> seen;
        for (int i = start; i < arr.size(); i++)
        {
            if (seen.find(arr[i]) == seen.end())
            {
                swap(arr[start], arr[i]);
                generatePermutations(arr, start + 1, result);
                swap(arr[start], arr[i]);
                seen[arr[i]] = true;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &arr)
    {
        vector<vector<int>> result;
        generatePermutations(arr, 0, result);
        return result;
    }
};

int main(void)
{
    vector<int> arr = {1, 1, 2, 2};
    Solution solution;
    printDoubleIntArray(solution.permuteUnique(arr), " ");

    return 0;
}