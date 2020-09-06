class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> values;
        
        for(int num: nums) {
            if (values.size() == 0 || values.back().first != num) {
                values.push_back(make_pair(num, 0));
            }
            
            values.back().second += num;
        }
        
        int n = values.size();
        vector<int> res(n, 0);
        res[0] = values.front().second;
        int result = res[0];
        
        for(int i=1; i<n; i++) {
            int currentResult = values[i].second, val = values[i].first;
            
            if (values[i-1].first + 1 == val) {
                currentResult += (i-3 >= 0 ? max(res[i-3], res[i-2]) : (i - 2 >= 0 ? res[i-2] : 0));
            } else {
                currentResult += (i-2 >= 0 ? max(res[i-2], res[i-1]) : res[i-1]);
            }
            
            res[i] = currentResult;
            result = max(result, currentResult);
        }
        
        
        return result;
    }
};

/*
[3, 4, 2]

[2, 3, 4]
[2, 3, 6]
*/