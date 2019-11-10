#include "array.cpp"

class Solution
{
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
    // next permutation based approach
    void generateParenthesisCombinations(string str, int start, vector<string> &result)
    {
        if (str.size() == start)
        {
            if (isValid(str))
            {
                result.push_back(str);
            }
            return;
        }

        str[start] = '(';
        generateParenthesisCombinations(str, start + 1, result);
        str[start] = ')';
        generateParenthesisCombinations(str, start + 1, result);
    }
    // balanced parenthesis based approach
    void generateBalancedParenthesisCombinations(string str, int start, int end, int n, vector<string>& result) {
        if (str.size() == 2*n) {
            result.push_back(str);
            return;
        }

        if (start <n ) {
            generateBalancedParenthesisCombinations(str+"(", start+1, end, n, result);
        }

        if (end < start ) {
            generateBalancedParenthesisCombinations(str+")", start, end+1, n, result);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string str(2 * n, ' ');
        vector<string> result;
        // generateParenthesisCombinations(str, 0, result);
        generateBalancedParenthesisCombinations("", 0, 0, n, result);
        return result;
    }
};

int main(void)
{
    Solution solution;
    vector<string> permutations = solution.generateParenthesis(3);
    for (int i = 0; i < permutations.size(); i++)
    {
        cout << permutations[i] << endl;
    }
    return 0;
}