class Solution {
public:
    int numDecodings(string s) {
        int prev1 = 1, prev2 = 1, n = s.size(), current = 0;
        
        for(int i=n-1; i>=0; i--) {
            current = 0;
            
            if (s[i] != '0') {
                int twoDigitValue = i + 2 <= n ? stoi(s.substr(i, 2)) : 0;
                int oneDigitValue = stoi(s.substr(i, 1));
            
                if (twoDigitValue >= 1 && twoDigitValue <= 26) {
                    current += prev2;
                }

                if (oneDigitValue >= 1 && oneDigitValue <= 9) {
                    current += prev1;
                }
            }
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
};