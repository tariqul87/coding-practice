#include "array.cpp"

class Solution
{
public:
    string getBaseValue(unordered_map<string, string> &similarityMap, string word)
    {
        if (similarityMap.find(word) == similarityMap.end())
        {
            return word;
        }

        string baseValue = word;
        while (similarityMap[baseValue] != baseValue)
        {
            baseValue = similarityMap[baseValue];
        }

        return baseValue;
    }
    void updateSimilarity(unordered_map<string, string> &similarityMap, vector<vector<string>> &pairs)
    {
        for (vector<string> pair : pairs)
        {
            string baseValue1 = getBaseValue(similarityMap, pair[0]);
            string baseValue2 = getBaseValue(similarityMap, pair[1]);
            similarityMap[baseValue2] = baseValue1;
            similarityMap[pair[0]] = baseValue1;
            similarityMap[pair[1]] = baseValue1;
        }
    }
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs)
    {
        if (words1.size() != words2.size())
        {
            return false;
        }

        unordered_map<string, string> similartiyMap;
        updateSimilarity(similartiyMap, pairs);

        for (int i = 0; i < words1.size(); i++)
        {
            string word1 = words1[i], word2 = words2[i];
            if (word1 != word2 && getBaseValue(similartiyMap, word1) != getBaseValue(similartiyMap, word2))
            {
                return false;
            }
        }

        return true;
    }
};

int main(void)
{
    vector<string> words1 = {"an", "extraordinary", "meal"};
    vector<string> words2 = {"one", "good", "dinner"};
    vector<vector<string>> pairs = {{"great", "good"}, {"extraordinary", "good"}, {"well", "good"}, {"wonderful", "good"}, {"excellent", "good"}, {"fine", "good"}, {"nice", "good"}, {"any", "one"}, {"some", "one"}, {"unique", "one"}, {"the", "one"}, {"an", "one"}, {"single", "one"}, {"a", "one"}, {"truck", "car"}, {"wagon", "car"}, {"automobile", "car"}, {"auto", "car"}, {"vehicle", "car"}, {"entertain", "have"}, {"drink", "have"}, {"eat", "have"}, {"take", "have"}, {"fruits", "meal"}, {"brunch", "meal"}, {"breakfast", "meal"}, {"food", "meal"}, {"dinner", "meal"}, {"super", "meal"}, {"lunch", "meal"}, {"possess", "own"}, {"keep", "own"}, {"have", "own"}, {"extremely", "very"}, {"actually", "very"}, {"really", "very"}, {"super", "very"}};

    Solution s;

    cout << (s.areSentencesSimilarTwo(words1, words2, pairs) ? "true" : "false") << endl;
}