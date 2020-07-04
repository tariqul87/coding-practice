#include "array.cpp"

class Solution {
public:
	int getTwoSumSmaller(vector<int>& nums, int target, int left) {
		int sum = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                sum += right - left;
                left++;
            } else {
                right--;
            }
        }
        
        return sum;
	}
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        int sum = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size() - 2; i++) {
        	sum += getTwoSumSmaller(nums, target - nums[i], i+1);
        }

        return sum;
    }
};

int main(void) {
	vector<int> nums = {-2,0,1,3};
	Solution s;

	cout<<s.threeSumSmaller(nums, 2)<<endl;

	return 0;
}