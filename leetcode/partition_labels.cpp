#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        map<char, vector<int>> charToIndex;

        for (int i = 0; i < S.size(); i++)
        {
            char ch = S[i];

            if (!charToIndex[ch].size())
            {
                charToIndex[ch].push_back(i);
                charToIndex[ch].push_back(i);
            }
            else
            {
                charToIndex[ch][1] = i;
            }
        }

        int currentFirst = 0;
        int currentLast = charToIndex[S[0]][1];
        vector<int> result;

        for (int i = 0; i < S.size(); i++)
        {
            char ch = S[i];

            int last = charToIndex[ch][1];
            if (i == currentLast)
            {
                result.push_back(currentLast - currentFirst + 1);
                currentFirst = i + 1;
                if (S[i + 1])
                {
                    currentLast = charToIndex[S[i + 1]][1];
                }
            }
            else if (last > currentLast)
            {
                currentLast = last;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution solution;
    vector<int> result = solution.partitionLabels("ababcbacadefegdehijhklij");
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}