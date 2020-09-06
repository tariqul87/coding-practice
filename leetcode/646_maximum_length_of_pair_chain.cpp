bool compare(vector<int>& A, vector<int>& B) {
    return A.back() < B.back();
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        
        int prevEnd = INT_MIN;
        int count = 0;
        for(vector<int> pair: pairs) {
            if (prevEnd < pair.front()) {
                prevEnd = pair.back();
                count++;
            }
        }
        
        return count;
    }
};