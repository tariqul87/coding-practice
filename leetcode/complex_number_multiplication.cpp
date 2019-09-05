#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parseNumberFromString(string str)
    {
        vector<int> numbers;
        int pos = str.find("+");
        string firstNumber, secondNumber;
        firstNumber = str.substr(0, pos);
        secondNumber = str.substr(pos + 1, str.size() - pos - 2);

        if (!firstNumber.size())
        {
            firstNumber = "0";
        }

        if (!secondNumber.size())
        {
            secondNumber = "0";
        }

        numbers.push_back(stoi(firstNumber));
        numbers.push_back(stoi(secondNumber));
        return numbers;
    }
    string complexNumberMultiply(string a, string b)
    {
        vector<int> n1 = parseNumberFromString(a), n2 = parseNumberFromString(b);
        int x = n1[0] * n2[0] - n1[1] * n2[1];
        int y = n1[0] * n2[1] + n2[0] * n1[1];
        return (x == 0 ? "0" : to_string(x)) + "+" + (y == 0 ? "0i" : to_string(y) + "i");
    }
};

int main(void)
{
    Solution solution;
    cout << solution.complexNumberMultiply("1+-1i", "1+-1i") << endl;
}