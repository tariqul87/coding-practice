#include "array.cpp"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || target <= nums.front()) {
        	return 0;
        }

        if (target >= nums.back()) {
        	return target > nums.back() ? nums.size() : nums.size() - 1;
        }

        int low = 0, high = nums.size() - 1, mid;

        while(low <= high) {
        	mid = (low + high) / 2;

        	if (target > nums[mid]) {
        		low = mid + 1;
        	} else if (mid > 0 && target <= nums[mid-1]) {
        		high = mid - 1;
        	} else {
        		break;
        	}
        }

        return mid;
    }
};

int main(void) {
	vector<int> arr = {1,2,3,4,5};
	int number = 4;
	Solution s;
	cout<<s.searchInsert(arr, number);

	return 0;
}