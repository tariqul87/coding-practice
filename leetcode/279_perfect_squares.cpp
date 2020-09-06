class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i*i <= n; i++) {
            squares.push_back(i*i);
            dp[squares.back()] = 1;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<squares.size() && squares[j] <= i; j++) {
                int square = squares[j];
                dp[i] = min(dp[i-square] + dp[square], dp[i]);
            }
        }
        
        return dp[n];
    }
};