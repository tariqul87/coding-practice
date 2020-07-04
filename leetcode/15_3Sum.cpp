#include "array.cpp"

class Solution {
	vector<vector<int>> result;
public:
	void updateResult(vector<int>& nums, int target, int start, int end) {
		while(start < end) {
			int sum = nums[start] + nums[end];

			if (sum < target) {
				start++;
			} else if (sum > target) {
				end--;
			} else {
				result.push_back({-target, nums[start], nums[end]});
				start++;
				end--;

				while(start < end && nums[start] == nums[start-1]) {
					start++;
				}

				while(end > start && nums[end] == nums[end+1]) {
					end--;
				}
			}
		}
	}
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
        	updateResult(nums, -nums[i], i+1, nums.size() - 1);
        	
        	while(i + 1 < nums.size() && nums[i] == nums[i+1]) {
        		i++;
        	}
        }

        return result;
    }
};

int main(void) {
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	Solution s;

	printDoubleIntArray(s.threeSum(nums), " ");
}