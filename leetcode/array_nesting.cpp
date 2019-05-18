#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int calculateLength(vector<int> &nums, int index, vector<bool> &seen, vector<int> &lengthList)
    {
        if (nums[index] > nums.size() || seen[index])
        {
            return 0;
        }

        seen[index] = true;
        lengthList[index] = 1 + calculateLength(nums, nums[index], seen, lengthList);

        return lengthList[index];
    }
    int arrayNesting(vector<int> &nums)
    {
        int size = nums.size(), len = 0;
        vector<int> lengthList;
        vector<bool> seen;

        for (int i = 0; i < size; i++)
        {
            lengthList.push_back(0);
            seen.push_back(false);
        }

        for (int i = 0; i < size; i++)
        {
            if (!lengthList[i])
            {
                fill(seen.begin(), seen.end(), false);
                lengthList[i] = calculateLength(nums, i, seen, lengthList);
            }
            if (len < lengthList[i])
            {
                len = lengthList[i];
            }
        }

        return len;
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<int> array;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }

    Solution solution;
    int result = solution.arrayNesting(array);
    cout << result << endl;

    return 0;
}