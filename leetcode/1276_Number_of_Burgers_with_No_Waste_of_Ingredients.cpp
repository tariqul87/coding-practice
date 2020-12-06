#include "array.cpp"

class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        vector<int> result;
        if (t-2*c >= 0 && (t-2*c) % 2 == 0) {
            int x = (t-2*c) / 2;
            int y = c - x;
            
            if (y >= 0) {
                result = {x, y};
            }
        }
        
        return result;
    }
};

/*
2x + 4y = t
2 - 2y + 4y = t
2y = t - 2
y = (t - 2) / 2;
*/