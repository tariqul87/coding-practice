#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        map<char, bool> seenTiles;
        map<string, bool> seenStrings;
        for (int i = 0; i < tiles.size(); i++)
        {
            seenTiles[tiles[i]] = false;
        }

        vector<string> possibleStrings;
        for (int i = 0; i < tiles.size(); i++)
        {
            char ch = tiles[i];
            int size = possibleStrings.size();
            if (!seenTiles[tiles[i]])
            {
                seenTiles[tiles[i]] = true;
                possibleStrings.push_back(tiles.substr(i, 1));
            }

            for (int j = 0; j < size; j++)
            {
                string str = possibleStrings[j];
                for (int k = 0; k < str.size(); k++)
                {
                    string possibleString = str.substr(0, k) + tiles.substr(i, 1) + str.substr(k, str.size());
                    if (!seenStrings[possibleString])
                    {
                        seenStrings[possibleString] = true;
                        possibleStrings.push_back(possibleString);
                    }
                }
                string possibleString = str + tiles.substr(i, 1);
                if (!seenStrings[possibleString])
                {
                    seenStrings[possibleString] = true;
                    possibleStrings.push_back(possibleString);
                }
            }
        }

        return possibleStrings.size();
    }
};

int main(void)
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.numTilePossibilities(str) << endl;
    return 0;
}