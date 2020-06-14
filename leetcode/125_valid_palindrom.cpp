#include "array.cpp"

class Solution
{
public:
    char toLowerChar(char ch)
    {
        return ch >= 'A' && ch <= 'Z' ? ch + ('a' - 'A') : ch;
    }
    bool isAlphaNeumeric(char ch)
    {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }
    string getAlphaNeumericString(string s)
    {
        string result = "";

        for (char ch : s)
        {
            if (isAlphaNeumeric(ch))
            {
                result.push_back(toLowerChar(ch));
            }
        }

        return result;
    }
    bool isPalindrome(string s)
    {
        string alphaNeumericString = getAlphaNeumericString(s);
        int size = alphaNeumericString.size();

        for (int i = 0; i < size / 2; i++)
        {
            if (alphaNeumericString[i] != alphaNeumericString[size - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};

int main(void)
{
    string str = "A man, a plan, a canal: Panama";
    Solution s;
    cout << (s.isPalindrome(str) ? "Yes" : "No") << endl;

    return 0;
}