class Solution {
public:
    bool isPossible(vector<int>& nums,int value,int k, int maxValue, int index) {    
        if (index == nums.size()) {
            return k == 0;
        }
        
        if (k == 0) {
            return false;
        }
        
        int i = index;
        
        for(; i<nums.size() && value + nums[i] <= maxValue; i++) {
            swap(nums[i], nums[index]);
            
            int currentValue = value + nums[index];
            if (currentValue < maxValue && isPossible(nums, currentValue, k, maxValue, index+1)) {
                return true;
            } else  if (currentValue == maxValue && isPossible(nums, 0, k-1, maxValue, index+1)) {
                return true;
            }
            
            swap(nums[i], nums[index]);
        }
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        
        sort(nums.begin(), nums.end());
        for(int num: nums) {
            sum += num;
        }
        
        if (k > nums.size() || sum % k != 0 || nums.back() > (sum / k)) {
            return false;
        }
        
        vector<int> sets(k, 0);
        return isPossible(nums, 0, k, sum/k, 0);
    }
};
/*
[4, 3, 2, 3, 5, 2, 1]
sum = 20
k = 4, single set sum = 20/4 = 5
*/