#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string morseCode(string word)
    {
        vector<string> codes({".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."});
        string code = "";

        for (int i = 0; i < word.size(); i++)
        {
            code += codes[word[i] - 'a'];
        }

        return code;
    }
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> output;

        for (int i = 0; i < words.size(); i++)
        {
            string code = morseCode(words[i]);
            bool found = false;
            for (int j = 0; j < output.size(); j++)
            {
                if (output[j] == code)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                output.push_back(code);
            }
        }

        return output.size();
    }
};

int main(void)
{
    vector<string> words({"gin", "zen", "gig", "msg"});
    Solution solution;
    cout << solution.uniqueMorseRepresentations(words) << endl;
    return 0;
}