#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> tree;
        tree.push_back(label);

        int power = 1;
        while (pow(2, power + 1) <= label)
        {
            power++;
        }

        cout << "Lowest power: " << power << endl;

        while (label > 1)
        {
            label = label / 2;
            label = pow(2, power) - 1 - label + pow(2, power - 1);
            tree.push_back(label);

            power--;
        }
        reverse(tree.begin(), tree.end());

        return tree;
    }
};

int main(void)
{
    Solution solution;
    vector<int> result = solution.pathInZigZagTree(26);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}