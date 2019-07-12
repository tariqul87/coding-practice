#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        bool seen = false;
        for(int i=0; i<bits.size(); i++) {
            if (bits[i] == 1) {
                i++;
                seen = false;
            } else {
                seen = true;
            }
        }

        return seen;
    }
};

int main(void)
{
    int n;
    vector<int> bits;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bits.push_back(x);
    }

    Solution s;
    cout << s.isOneBitCharacter(bits) << endl;

    return 0;
}