class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() ==0) {
            return {};
        }
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};
        int n = nums.size(), i = 0;
        
        while(i < n) {
            int count = 0;
            while(count + i < n && nums[count+i] == nums[i]) {
                count++;
            }
            
            int size = result.size();
            for(int j=0; j<size; j++) {
                vector<int> instance = result[j];
                for(int k=0; k<count; k++) {
                    instance.push_back(nums[i]);
                    result.push_back(instance);
                }
            }
            
            i+=count;
        }
        
        return result;
    }
};