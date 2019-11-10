#include "array.cpp"

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() -1;
        while (low < high) {
            int mid = (high + low) / 2;

            if ((mid - low) %2 == 0){
                if(nums[mid] == nums[mid - 1]) {
                    high = mid;
                } else if (nums[mid] == nums[mid+1]) {
                    low = mid;
                } else return nums[mid];
            } else {
                if(nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                } else if (nums[mid] == nums[mid+1]) {
                    high = mid - 1;
                } else return nums[mid];
            }
        }

        return nums[low];
    }
};

int main(void)
{
    vector<int> nums = {0,1,1,2,2,5,5};
    Solution solution;
    cout << solution.singleNonDuplicate(nums) << endl;

    return 0;
}