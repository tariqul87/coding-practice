#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string sum = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int max_size = max(a.size(), b.size());

        char carry = '0';
        for (int i = 0; i < max_size; i++)
        {
            int add = ((int)(carry - '0'));
            if (i < a.size())
            {
                add += ((int)(a[i] - '0'));
            }

            if (i < b.size())
            {
                add += ((int)(b[i] - '0'));
            }

            if (add > 1)
            {
                carry = '1';
            }
            else
            {
                carry = '0';
            }

            sum = (add % 2 == 0 ? "0" : "1") + sum;
        }

        return carry == '0' ? sum : "1" + sum;
    }
};

int main(void)
{
    string a, b;

    cin >> a >> b;

    Solution s;
    cout << s.addBinary(a, b) << endl;

    return 0;
}