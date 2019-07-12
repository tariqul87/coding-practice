#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string result;
        for (int i = 0; i < address.size(); i++)
        {
            if (address[i] == '.')
            {
                result.push_back('[');
                result.push_back('.');
                result.push_back(']');
            }
            else
            {
                result.push_back(address[i]);
            }
        }

        return result;
    }
};

int main(void)
{
    string ip = "192.168.15.1";
    Solution solution;
    cout << solution.defangIPaddr(ip) << endl;
}