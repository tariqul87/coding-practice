#include "array.cpp"

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> xorMap;
        int value = 0, result = 0;
        xorMap[value] = make_pair(1, 0);
        
        for(int i=0; i<arr.size(); i++) {
            value = value ^ arr[i];
            
            if (xorMap.find(value) != xorMap.end()) {
                int count = xorMap[value].first, sum = xorMap[value].second;
                result += (i * count - sum);
                // cout<<i<<" "<<result<<endl;
            } else {
                xorMap[value] = make_pair(0, 0);
            }
            
            xorMap[value].first++;
            xorMap[value].second += i+1;
        }
        
        return result;
    }
};