#include "./array.cpp"


class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> grid;

        for(int i=0; i<s.size(); i++) {
            vector<bool> temp(s.size(), false);
            grid.push_back(temp);
        }

        int count = 0;

        for(int i=0; i<s.size();  i++) {
            grid[i][i] = true;
            count++;
            for(int j=i-1; j>=0; j--) {
                if(s[i] == s[j] && (i-j == 1 || grid[i-1][j+1])) {
                    grid[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};

int main(void) {
    string s = "abccb";
    Solution solution;
    cout<<solution.countSubstrings(s)<<endl;
    return 0;
}
