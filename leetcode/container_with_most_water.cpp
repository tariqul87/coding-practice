#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        vector<int> seen;
        int result = -1;
        seen.push_back(0);

        for (int i = 1; i < height.size(); i++)
        {
            for (int j = 0; j < seen.size(); j++)
            {
                int size = abs(i - seen[j]) * min(height[i], height[seen[j]]);
                if (size > result)
                {
                    result = size;
                }
            }
            if (height[i] > height[seen.back()])
            {
                seen.push_back(i);
            }
        }

        return result;
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

    Solution s;
    int result = s.maxArea(nums);
    cout << result << endl;
    return 0;
}