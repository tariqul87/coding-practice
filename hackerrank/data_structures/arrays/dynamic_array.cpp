#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    long long int n, q, lastAnswer = 0;
    cin >> n >> q;
    vector<vector<long long int>> seq;
    vector<long long int> result;

    seq.resize(n);

    for (int i = 0; i < q; i++)
    {
        long long int a, x, y;
        cin >> a >> x >> y;
        long long int index = (x ^ lastAnswer) % n;

        if (a == 1)
        {
            seq[index].push_back(y);
        }
        else if (a == 2)
        {
            long long int newLastAnswer = seq[index][y % seq[index].size()];
            if (newLastAnswer)
            {
                lastAnswer = newLastAnswer;
                result.push_back(lastAnswer);
            }
        }
    }
    vector<long long int> trueResult;

    for (auto iterator = result.begin(); iterator != result.end(); iterator++)
    {
        cout << *iterator << endl;
    }
}