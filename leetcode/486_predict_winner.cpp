class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> dp;
        
        for(int i=0; i<n; i++) {
            dp.push_back({});
            for(int j=0; j<n; j++) {
                dp.back().push_back(make_pair(0, 0));
            }
        }
        dp[0][0].first = nums.front();
        
        for(int j=1; j<n; j++) {
            int sum = nums[j];
            dp[j][j].first = nums[j];
            
            for(int i=j-1; i>=0; i--) {
                sum += nums[i];
                int playerOnePoint = max(nums[i] + dp[i+1][j].second, nums[j] + dp[i][j-1].second);
                int playerTwoPoint = sum - playerOnePoint;
                dp[i][j].first = playerOnePoint;
                dp[i][j].second = playerTwoPoint;
                
                // cout<<"["<<i<<","<<j<<"]: player1 = "<<playerOnePoint<<", player2 = "<<playerTwoPoint<<endl;
            }
        }
        
        
        return dp[0][n-1].first >= dp[0][n-1].second;
    }
};

/*
[1, 5, 233, 7]

[1] => player1 = 1, player2 = 0
[1, 2]  =>  [2]         player1 = 2, player2 = 1
            [1,2]       player1 = 2 + player2[0], 1 + player2[1] = 2
                        player2 = 1
            [1,2,5]     player1 = 1 + player
*/