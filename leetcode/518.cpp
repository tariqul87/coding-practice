class Solution {
public:
    int change(int amount, vector<int>& coins) {        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for(int coin: coins) {
            for(int val=1; val<=amount; val++) {
                if (val >= coin) {
                    dp[val] += dp[val - coin];
                }
            }
        }
        
        return dp[amount];
    }
};

/*
0 1 2 3 4 5
1 1 1 1 1 1 => 1
1 1 2 2 3 3 => 2
*/