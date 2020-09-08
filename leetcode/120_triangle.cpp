class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle.back().size() == 0) {
            return 0;
        }
        
        vector<int> dp = triangle.back();
        int n = triangle.back().size();
        
        for(int i=n-2; i>=0; i--) {
            int adjacentValue = triangle[i][i];
            for(int j=0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }
};