#include "array.cpp"

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') {
            i++;
        }

        bool negative;
        if (s[i] == '+' || s[i] == '-') {
            negative = s[i] == '-' ? true : false;
            i++;
        }
        
        int j = i;
        while(j<s.size() && s[j] >= '0' && s[j] <= '9') {
            j++;
        }
        
        string numericStr = s.substr(i, j-i);
        i = 0;
        
        long result = 0;
        
        while(i < numericStr.size()) {
            int val = numericStr[i] - '0';
            result = negative ? result * 10 - val : result * 10 + val;
            
            if (result > INT_MAX) {
                return INT_MAX;
            } else if (result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        
        return result;
    }
};