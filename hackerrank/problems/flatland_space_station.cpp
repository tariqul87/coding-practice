#include <bits/stdc++.h>
using namespace std;

int max_distance(int n, vector<int> stations)
{
    sort(stations.begin(), stations.end());
    int max = stations[0] - 0 > n - 1 - stations.back() ? stations[0] - 0 : n - 1 - stations.back();

    for (int i = 0; i < stations.size() - 1; i++)
    {
        int distance = (stations[i + 1] - stations[i]) / 2;
        max = max > distance ? max : distance;
    }

    return max;
}

int main(void)
{
    int n, m;
    vector<int> stations;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        stations.push_back(x);
    }

    cout << max_distance(n, stations) << endl;
    return 0;
}