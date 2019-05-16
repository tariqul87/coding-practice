#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &sorted)
    {
        vector<vector<int>> result;
        if (sorted.size() < 3)
        {
            return result;
        }

        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < sorted.size() - 2; i++)
        {
            if (i == 0 || (i > 0 && sorted[i] != sorted[i - 1]))
            {

                int j = i + 1, k = sorted.size() - 1;
                while (j < k)
                {
                    if (sorted[i] + sorted[j] + sorted[k] < 0)
                    {
                        j++;
                    }
                    else if (sorted[i] + sorted[j] + sorted[k] > 0)
                    {
                        k--;
                    }
                    else
                    {
                        vector<int> triplet;
                        triplet.push_back(sorted[i]);
                        triplet.push_back(sorted[j]);
                        triplet.push_back(sorted[k]);
                        result.push_back(triplet);

                        int left = sorted[j];
                        int right = sorted[k];

                        while (left == sorted[j] && j < k)
                        {
                            j++;
                        }

                        while (right == sorted[k] && j < k)
                        {
                            k--;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main(void)
{
    int n, target;
    vector<int> array;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }

    vector<vector<int>> result;
    Solution *s = new Solution();
    result = s->threeSum(array);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}