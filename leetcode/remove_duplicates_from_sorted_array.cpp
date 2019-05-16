#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            while (i < nums.size() && nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
            }
        }

        return nums.size();
    }
};

int main(void)
{
    int n;
    vector<int> nums;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    int result = solution.removeDuplicates(nums);
    cout << "Result: " << result << endl;

    return 0;
}