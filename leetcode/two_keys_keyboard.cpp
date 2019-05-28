#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int minSteps(int n)
    {
        int count = 1;
        int ans = 0;
        int paste = 0;

        while (count != n)
        {
            if (count * 2 <= n && (n - 2 * count) % count == 0)
            {
                ans += 2;
                paste = count;
                count *= 2;
            }
            else
            {
                ans++;
                count += paste;
            }
        }

        return ans;
    }
};

int main(void)
{
    int n;
    cin >> n;
    Solution solution;
    cout << solution.minSteps(n) << endl;
    return 0;
}