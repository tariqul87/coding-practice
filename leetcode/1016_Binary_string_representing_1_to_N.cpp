#include "array.cpp"

class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=1; i<=N; i++) {
            string b = bitset<32>(i).to_string();
            if (S.find(b.substr(b.find("1"))) == string::npos) {
                return false;
            }
        }
        
        return true;
    }
};