#include "array.cpp"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> indexMap;
        for(int i=0; i<nums.size(); i++) {
            nums[i] += (i == 0 ? 0 : nums[i-1]);
            
            indexMap[nums[i]] = i;
        }
        
        int result = 0;
        for(int i=0; i<nums.size(); i++) {
            long target = (long)(nums[i]) + (long)(k);
            
            if (target > INT_MAX|| target < INT_MIN) {
                continue;
            }
            
            if (indexMap.find((int)(target)) != indexMap.end()) {
                result = max(result, indexMap[target] - i);
            }
        }
        
        if (indexMap.find(k) != indexMap.end()) {
            result = max(result, indexMap[k] + 1);
        }
        
        return result;
    }
};