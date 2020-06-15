#include "array.cpp"

class Solution {
    unordered_map<string, bool> history;
public:
    bool canWin(string s) {
        if (s.size() < 1) {
            return false;
        }
        
        if (history.find(s) != history.end()) {
            return history[s];
        }
        
        bool noMove = true;
        bool opponentWins = true;
        for(int i=0; i<s.size() - 1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                noMove = false;
                s[i] = '-';
                s[i+1] = '-';
                
                opponentWins = opponentWins && canWin(s);
                
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        
        history[s] = !noMove && !opponentWins;
        return history[s];
    }
};

int main(void) {
    Solution s;
    cout<<(s.canWin("++++") ? "YES" : "NO")<<endl;

    return 0;
}