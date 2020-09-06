class Solution {
public:
    vector<vector<int>> dirs = {{1, 2}, {1,-2},{2,1},{2,-1},{-1, 2}, {-1,-2},{-2,1},{-2,-1}};
    double getUpdatedValue(vector<vector<double>>& dp, int i, int j) {
        double count = 0;
        int N = dp.size();
        
        for(vector<int> dir: dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if (x >= 0 && x < N && y >= 0 && y < N) {
                count += dp[x][y];
            }
        }
        
        return count;
    }
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 1.0));
        
        for(int k=0; k<K; k++) {
            vector<vector<double>> temp;
            for(int i=0; i<N; i++) {
                temp.push_back({});
                for(int j=0; j<N; j++) {
                    temp[i].push_back(getUpdatedValue(dp, i, j));
                }
            }
            
            dp = temp;
        }
        
        return dp[r][c] / pow(8, K);
    }
};