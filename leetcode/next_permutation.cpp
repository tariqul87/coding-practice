#include "array.cpp"

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        reverse(nums.begin() + i + 1, nums.end());
        if (i >= 0)
        {
            int j = i + 1;
            while (j < nums.size() && nums[i] >= nums[j])
            {
                j++;
            }

            if (j == nums.size())
            {
                nums.push_back(nums[0]);
                nums.erase(nums.begin());
            }
            else
            {
                swap(nums[i], nums[j]);
            }
        }
    }
};

int main(void)
{
    vector<int> arr = {1, 4, 3, 2};
    Solution solution;
    solution.nextPermutation(arr);
    printIntArray(arr, " ");
    return 0;
}