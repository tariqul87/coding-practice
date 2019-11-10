#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string str)
    {
        int start = 0, seenFirst = 0, seenLast = 0;
        string result = "";

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                seenFirst++;
            }
            else
            {
                seenLast++;
            }

            if (seenFirst == seenLast)
            {
                result += str.substr(start + 1, i - start - 1);
                start = i + 1;
                seenFirst = seenLast = 0;
            }
        }

        return result;
    }
};

int main(void)
{
    string str = "()()";

    Solution solution;
    cout << solution.removeOuterParentheses(str) << endl;
    return 0;
}