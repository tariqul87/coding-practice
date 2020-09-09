class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 0, resultIndex = 0;
        
        vector<vector<int>> results(nums.size());
        results[0] = {nums[0]};
        
        for(int i=1; i<nums.size(); i++) {
            int val = nums[i];
            for(int j=0; j<i; j++) {
                if (results[j].size() != 0 && val % results[j].back() == 0 
                    && results[j].size() > results[i].size()) {
                    results[i] = results[j];
                }
            }
            
            results[i].push_back(val);
            if (results[i].size() > maxLen) {
                maxLen = results[i].size();
                resultIndex = i;
            }
        }
        
        return results[resultIndex];
    }
};

/*
[1,2,4,8]

1 = [1,2]
2 = [2]
*/