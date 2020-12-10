#include "array.cpp"

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) {
            return -1;
        }
        
        string str = to_string(n);
        int i = str.size() - 2;
        int j = i+1;
        
        while(i >= 0 && str[i] >= str[i+1]) {
            i--;
        }
        
        if (i < 0) {
            return -1;
        }
        
        pair<char, int> p = make_pair(('9' + 1), -1);
        
        while(i < j) {
            if (str[j] > str[i] && str[j] < p.first) {
                p = make_pair(str[j], j);
            }
            j--;
        }
        
        swap(str[i], str[p.second]);
        sort(str.begin() + i + 1, str.end());
        
        long long result = stol(str);
        
        return result > INT_MAX ? -1 : result;
    }
};