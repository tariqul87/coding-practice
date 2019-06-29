#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
       int count = 0; 
        for(int i =0; i<J.size(); i++) {
            for(int j=0; j < S.size(); j++) {
                if(J[i] == S[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main(void)
{
    string J, S;
    cin >> J >> S;

    Solution solution;
    cout << solution.numJewelsInStones(J, S) << endl;

    return 0;
}