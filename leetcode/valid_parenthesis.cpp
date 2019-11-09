#include "array.cpp"

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 0)
        {
            return true;
        }

        vector<char> stack;
        stack.push_back(s[0]);

        for (int i = 1; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                stack.push_back(s[i]);
                break;
            case ')':
                if (stack.size() && stack.back() == '(')
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }

        return stack.size() == 0 ? true : false;
    }
};

int main(void)
{
    string s = "(()))(";

    Solution solution;
    cout << solution.isValid(s) << endl;
    return 0;
}