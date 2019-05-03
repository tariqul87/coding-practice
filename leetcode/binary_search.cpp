#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int binarySearch(vector<int> &nums, int low, int high, int target)
    {
        int mid = low + (high - low) / 2;

        if (low > high)
        {
            return -1;
        }

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] < target)
        {
            return binarySearch(nums, mid + 1, high, target);
        }

        return binarySearch(nums, low, mid - 1, target);
    }
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
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
    int target;
    cin>>target;

    Solution solution;
    int result = solution.search(nums, target);
    cout << "Result: " << result << endl;

    return 0;
}