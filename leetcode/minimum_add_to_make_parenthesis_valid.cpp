#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        if (S.size() == 0)
        {
            return 0;
        }
        int i = 1;
        while (i < S.size())
        {
            if (i > 0 && S[i - 1] == '(' && S[i] == ')')
            {
                S.erase(i - 1, 2);
                i--;
            }
            else
            {
                i++;
            }
        }

        return S.size();
    }
};

int main(void)
{
    string str = "()))((";
    Solution solution;
    cout << solution.minAddToMakeValid(str) << endl;
}