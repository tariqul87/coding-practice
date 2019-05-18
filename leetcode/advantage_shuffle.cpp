#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        vector<int> result;

        sort(A.begin(), A.end());

        for (int i = 0; i < B.size(); i++)
        {
            int j = 0;
            while (j < A.size() && A[j] <= B[i])
            {
                j++;
            }
            if (j >= A.size())
            {
                j = 0;
            }

            result.push_back(A[j]);
            A.erase(A.begin() + j);
        }

        return result;
    }
};

int main(void)
{
    int n;
    vector<int> A, B;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        B.push_back(x);
    }

    Solution solution;
    vector<int> result = solution.advantageCount(A, B);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}