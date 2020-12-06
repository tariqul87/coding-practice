#include "array.cpp"

bool compare(const string &a, const string &b)
{
    return a.size() < b.size();
}

class Solution
{
public:
    unordered_map<string, vector<string>> successorMap;
    void generateSuccessors(vector<string> &words)
    {
        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_map<string, unordered_set<string>> seen;

        for (string str : words)
        {
            for (int i = 0; i < str.size(); i++)
            {
                string prefix = i == 0 ? "" : str.substr(0, i);
                string suffix = i == str.size() - 1 ? "" : str.substr(i + 1, str.size() - i - 1);
                string pre = prefix + suffix;

                if (wordSet.find(pre) != wordSet.end() && (seen.find(pre) == seen.end() || seen[pre].find(str) == seen[pre].end()))
                {
                    successorMap[pre].push_back(str);
                    seen[pre].insert(str);
                }
            }
        }
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), compare);
        generateSuccessors(words);
        unordered_map<string, int> chainLen;

        int result = 0;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            string word = words[i];

            int maxLen = 1;
            for (string successor : successorMap[word])
            {
                maxLen = max(maxLen, 1 + chainLen[successor]);
            }

            chainLen[word] = maxLen;
            result = max(maxLen, result);
        }

        return result;
    }
};