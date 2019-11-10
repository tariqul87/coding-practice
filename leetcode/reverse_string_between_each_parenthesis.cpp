#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int i = s.size() - 1, j = 0;

        while (i >= 0)
        {
            while (i >= 0 && s[i] != '(')
            {
                i--;
            }

            j = i;
            while (j < s.size() && s[j] != ')')
            {
                j++;
            }

            if (i >= 0 && j < s.size() && s[i] == '(' && s[j] == ')')
            {
                s.erase(s.begin() + j);
                s.erase(s.begin() + i);
                if (j - i > 1)
                {
                    reverse(s.begin() + i, s.begin() + j - 1);
                }
                j--;
            }
        }

        return s;
    }
};

int main(void)
{
    Solution s;
    cout << s.reverseParentheses("ta()usw((((a))))") << endl;
    return 0;
}