class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i = 0, maxProfit = 0;
        
        while(i < n) {
             while(i+1 < n && prices[i] > prices[i+1]) {
                i++;
            }
            
            int start = i;
            int end = i;
            
            while(end+1 < n && prices[end] <= prices[end+1]) {
                end++;
            }
            
            if (start != end) {
                maxProfit += (prices[end] - prices[start]);
            }

            i = end+1;
        }
        
        return maxProfit;
    }
};