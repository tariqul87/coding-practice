#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool canReorderDoubled(vector<int> &nums)
    {
        int count[100001];
        memset(count, 0, 100001 * sizeof(int));
        for (int i = 0; i < nums.size(); i++)
        {
            count[abs(nums[i])]++;
        }

        if (count[0] % 2 == 1)
            return false;
        for (int i = 1; i < 50001; i++)
        {
            if (count[i] > count[i * 2])
            {
                return false;
            }
            count[i * 2] -= count[i];
            count[i] = 0;
        }

        return true;
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
    cout << solution.canReorderDoubled(nums) << endl;
}