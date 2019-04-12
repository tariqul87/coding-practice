#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        int result = nums[len - 1] + nums[len - 2] + nums[len - 3];

        for (int i = 0; i < len - 2; i++)
        {
            int j = i + 1, k = len - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    return target;
                }
                else
                {
                    if (abs(sum - target) < abs(target - result))
                    {
                        result = sum;
                    }

                    int left = nums[j];
                    int right = nums[k];

                    if (sum < target)
                    {
                        j++;
                        while (j < k && left == nums[j])
                        {
                            j++;
                        }
                                        }
                    else
                    {
                        k--;
                        while (j < k && right == nums[k])
                        {
                            k--;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main(void)
{
    int n, target;
    vector<int> nums;

    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution s;
    int result = s.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}