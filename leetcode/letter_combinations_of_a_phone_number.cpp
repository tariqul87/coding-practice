#include "array.cpp"

// normal calculation based approach
// class Solution
// {
// public:
//     vector<string> combineStrings(vector<string> str1, vector<string> str2)
//     {
//         vector<string> result;

//         for(int i=0; i<str1.size(); i++) {
//             for(int j=0; j<str2.size(); j++) {
//                 result.push_back(str1[i] + str2[j]);
//             }
//         }

//         return result;
//     }
//     vector<string> generateLetterCombinations(string digits, int low, int high, map<string, vector<string>> &seen)
//     {
//         if (high == low)
//         {
//             return seen[digits.substr(low, 1)];
//         }

//         string currentString = digits.substr(low, high - low + 1);
//         if (seen.find(currentString) != seen.end())
//         {
//             return seen[currentString];
//         }

//         int mid = (high + low) / 2;
//         vector<string> left = generateLetterCombinations(digits, low, mid, seen);
//         vector<string> right = generateLetterCombinations(digits, mid + 1, high, seen);

//         seen[currentString] = combineStrings(left, right);
//         return seen[currentString];
//     }
//     vector<string> letterCombinations(string digits)
//     {
//         if (digits.size() == 0) {
//             return {};
//         }
//         map<string, vector<string>> seen;
//         seen["1"] = {""};
//         seen["2"] = {"a", "b", "c"};
//         seen["3"] = {"d", "e", "f"};
//         seen["4"] = {"g", "h", "i"};
//         seen["5"] = {"j", "k", "l"};
//         seen["6"] = {"m", "n", "o"};
//         seen["7"] = {"p", "q", "r", "s"};
//         seen["8"] = {"t", "u", "v"};
//         seen["9"] = {"w", "x", "y", "z"};

//         return generateLetterCombinations(digits, 0, digits.size() - 1, seen);
//     }
// };

class Solution
{
    map<char, string> charSet;
    void generateLetterCombinations(string digits, int position, string currentStr, vector<string> &result)
    {
        if (position == digits.size())
        {
            result.push_back(currentStr);
            return;
        }

        if (charSet[digits[position]] == "") {
            generateLetterCombinations(digits, position + 1, currentStr, result);
            return;
        }

        for (int i = 0; i < charSet[digits[position]].size(); i++)
        {
            currentStr.push_back(charSet[digits[position]][i]);
            generateLetterCombinations(digits, position + 1, currentStr, result);
            currentStr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        vector<string> result;
        charSet['1'] = "";
        charSet['2'] = "abc";
        charSet['3'] = "def";
        charSet['4'] = "ghi";
        charSet['5'] = "jkl";
        charSet['6'] = "mno";
        charSet['7'] = "pqrs";
        charSet['8'] = "tuv";
        charSet['9'] = "wxyz";

        generateLetterCombinations(digits, 0, "", result);
        return result;
    }
};

int main(void)
{
    Solution solution;
    vector<string> permutations = solution.letterCombinations("2332");
    for (int i = 0; i < permutations.size(); i++)
    {
        cout << permutations[i] << endl;
    }
    return 0;
}