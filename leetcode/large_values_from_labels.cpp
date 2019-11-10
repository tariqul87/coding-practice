#include "array.cpp"

class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        vector<vector<int>> valueLabelPair;
        map<int, int> usedCount;

        for (int i = 0; i < values.size(); i++)
        {
            valueLabelPair.push_back({values[i], labels[i]});
            usedCount[labels[i]] = 0;
        }

        sort(valueLabelPair.begin(), valueLabelPair.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
            return a[0] > b[0];
        });

        int sum = 0, count = 0, i = 0;

        while(count < num_wanted && i < valueLabelPair.size()) {
            if (usedCount[valueLabelPair[i][1]] < use_limit) {
                sum += valueLabelPair[i][0];
                usedCount[valueLabelPair[i][1]]++;
                count++;
            }
            i++;
        }

        return sum;
    }
};

int main(void)
{
    vector<int> values = {2,6,3,6,5};
    vector<int> lables = {1,1,2,1,1};
    int numsWanted = 3, usageLimit = 1;
    Solution solution;

    cout << solution.largestValsFromLabels(values, lables, numsWanted, usageLimit) << endl;
    return 0;
}