#include <bits/stdc++.h>
#include "./template.cpp"
using namespace std;

class Solution
{
public:
    int getStones(vector<int> &piles, int i, int m, vector<int> &sums, vector<vector<int>> &hash)
    {
        if (i == piles.size()) {
            return 0;
        }
        if (piles.size() - i <= 2 * m)
        {
            return sums[i];
        }

        if (hash[i][m] != 0)
        {
            return hash[i][m];
        }

        int minVal = 1000001;
        for (int x = 1; x <= 2 * m; x++)
        {
            minVal = min(minVal, getStones(piles, i + x, max(x, m), sums, hash));
        }

        hash[i][m] = sums[i] - minVal;
        return hash[i][m];
    }
    int stoneGameII(vector<int> &piles)
    {
        vector<int> sums(piles.size());
        vector<vector<int>> hash(piles.size(), vector<int>(piles.size()));

        sums[piles.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; i--)
        {
            sums[i] = sums[i + 1] + piles[i];
        }

        return getStones(piles, 0, 1, sums, hash);
    }
};

int main(void)
{
    Solution solution;
    vector<int> arr({2, 7, 9, 4, 4});
    cout << solution.stoneGameII(arr) << endl;
    return 0;
}