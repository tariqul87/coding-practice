#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int n, m;
    vector<string> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.push_back(str);
    }

    cin >> m;
    vector<int> q;

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (!str.compare(s[j]))
            {
                count++;
            }
        }
        q.push_back(count);
    }

    for (int i = 0; i < m; i++)
    {
        cout << q[i] << endl;
    }
}