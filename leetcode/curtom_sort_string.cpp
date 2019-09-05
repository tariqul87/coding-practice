#include <bits/stdc++.h>
#include "./template.cpp"
using namespace std;

class Solution
{
public:
    string customSortString(string S, string T)
    {
        int count[26];
        bool present[26];
        memset(count, 0, sizeof(int) * 26);

        for (int i = 0; i < T.size(); i++)
        {
            int index = (int)(T[i] - 'a');
            count[index]++;
        }

        string result = "";

        for (int i = 0; i < S.size(); i++)
        {
            int index = (int)(S[i] - 'a');
            present[index] = true;

            for (int j = 0; j < count[index]; j++)
            {
                result += S[i];
            }
        }

        for (int i = 0; i < T.size(); i++)
        {
            int index = (int)(T[i] - 'a');
            if (!present[index])
            {
                result += T[i];
            }
        }

        return result;
    }
};

int main(void)
{
    Solution solution;
    cout << solution.customSortString("hucw", "utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh")
         << endl;
    return 0;
}