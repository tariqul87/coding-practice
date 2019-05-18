#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);

        for (int i = 0; i < nums.size(); i++)
        {
            int size = result.size();
            for (int j = 0; j < size; j++)
            {
                vector<int> newVector(result[j]);
                newVector.push_back(nums[i]);
                result.push_back(newVector);
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
                int newResultSize = result.size();
                for (int k = 0; k < size; k++)
                {
                    vector<int> newVector(result[newResultSize - size + k]);
                    newVector.push_back(nums[i]);
                    result.push_back(newVector);
                }
            }
        }

        return result;
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}