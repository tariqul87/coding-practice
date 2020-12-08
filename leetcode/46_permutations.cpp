#include "array.cpp"

class Solution {
public:
    vector<vector<int>> result;
    void generatePermutations(vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            generatePermutations(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        generatePermutations(nums, 0);
        return result;
    }
};