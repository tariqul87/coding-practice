class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int n = nums.size();
        vector<int> dp(n, 1), res(n+1, 1);
        res[1] = 1;
        
        for(int i=1; i<n; i++) {
            int currentMaxLen = dp[i];
            int currentRes = 1;
            // cout<<i<<"-------"<<endl;
            for(int j=0; j<i; j++) {
                if (nums[j] < nums[i]) {
                    int currentLen = dp[j] + 1;
                    
                    if (currentLen > currentMaxLen) {
                        currentMaxLen = currentLen;
                        currentRes = res[j];
                    } else if (currentMaxLen == currentLen) {
                        currentRes += res[j];
                        // cout<<currentMaxLen<<", current result: "<<currentRes<<endl;
                    }
                }
            }
            
            if (currentMaxLen > dp[i]) {
                dp[i] = currentMaxLen;
            }
            
            res[i] = currentRes;
        }
        
        int maxLen = INT_MIN, result = 0;
        
        for(int i=0; i<n; i++) {
            if (maxLen < dp[i]) {
                maxLen = dp[i];
                result = res[i];
            } else if (maxLen == dp[i]) {
                result += res[i];
            }
        }
        
        return result;
    }
};

/*
nums = [1,3,5,4,7,2,4,5]

dp   = [1,2,3,3,4,2,3,4]
res  = [1,1,1,1,2,1,2,3]

*/


