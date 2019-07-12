#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            map<char, char> patternToWord;
            set<char> seenPattern, seenWord;
            string word = words[i];
            bool found = true;
            for (int j = 0; j < pattern.size(); j++)
            {
                if (seenPattern.find(pattern[j]) == seenPattern.end() && seenWord.find(word[j]) == seenWord.end())
                {
                    patternToWord[pattern[j]] = word[j];
                    seenPattern.insert(pattern[j]);
                    seenWord.insert(word[j]);
                }
                else if (patternToWord[pattern[j]] != word[j])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};

int main(void)
{
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";

    Solution solution;
    vector<string> result = solution.findAndReplacePattern(words, pattern);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}