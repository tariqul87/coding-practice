#include "array.cpp"

class Solution
{
    bool targetFoundInCandidates(vector<int> &candidates, int target, int index)
    {
        if (target > candidates[candidates.size() - 1] || target < candidates[index])
        {
            return false;
        }

        int low = index, high = candidates.size() - 1;
        while (low < high)
        {
            int mid = (high + low) / 2;
            if (candidates[mid] == target)
            {
                return true;
            }
            else if (target <= candidates[mid])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (candidates[low] == target)
        {
            return true;
        }

        return false;
    }
    vector<vector<int>> combineSumFromIndex(vector<int> &candidates, int target, int index)
    {
        vector<vector<int>> result = {};
        if (candidates[index] > target)
        {
            return result;
        }

        if (targetFoundInCandidates(candidates, target, index))
        {
            result.push_back({target});
        }

        for (int i = index; i < candidates.size() && candidates[i] <= target; i++)
        {
            int num = candidates[i];
            vector<vector<int>> tempResult = combineSumFromIndex(candidates, target - num, i);
            if (tempResult.size() > 0)
            {
                for (int j = 0; j < tempResult.size(); j++)
                {
                    tempResult[j].insert(tempResult[j].begin(), num);
                    result.push_back(tempResult[j]);
                }
            }
        }

        return result;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        return combineSumFromIndex(candidates, target, 0);
    }
};

int main(void)
{
    vector<int> candidates = {1, 1, 1};
    int target = 0;
    Solution solution;
    printDoubleIntArray(solution.combinationSum(candidates, target), " ");
    return 0;
}