class Solution {
public:
    int getNextElementIndex(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return index;
        }
        
        int val = nums[index];
        
        while(index < nums.size() && nums[index] == val) {
            index++;
        }
        
        return index;
    }
    int getPreviousElementIndex(vector<int>& nums, int index) {
        if (index < 0) {
            return -1;
        }
        
        int val = nums[index];
        
        while(index >=0 && nums[index] == val) {
            index--;
        }
        
        return index;
    }
    vector<vector<int>> getTwoSumResult(vector<int>& nums, int startIndex, int target) {
        int endIndex = nums.size() - 1;
        vector<vector<int>> result = {};
        
        while(startIndex < endIndex) {
            int sum = nums[startIndex] + nums[endIndex];
            
            if (sum > target) {
                endIndex = getPreviousElementIndex(nums, endIndex);
            } else  if (sum < target) {
                startIndex = getNextElementIndex(nums, startIndex);
            } else {
                result.push_back({nums[startIndex], nums[endIndex]});
                endIndex = getPreviousElementIndex(nums, endIndex);
                startIndex = getNextElementIndex(nums, startIndex);
            }
        }
        
        return result;
    }
    bool isValueLessOrEqual(vector<int>& nums, int i, int target) {
        return nums[i] + nums[i+1] + nums[i+2] + nums[i+3] <= target;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), j;
        vector<vector<int>> result;
        
        for(int i=0; i<n-3 && isValueLessOrEqual(nums, i, target); ) {
            for (int j = i+1; j < n - 2;) {
                vector<vector<int>> twoSumResult = getTwoSumResult(nums, j+1, target - nums[i] - nums[j]);
                
                for(vector<int> currentResult: twoSumResult) {
                    result.push_back({nums[i], nums[j], currentResult[0], currentResult[1]});
                }
                j = getNextElementIndex(nums, j);
            }
            i = getNextElementIndex(nums, i);
        }
        
        return result;
    }
};











