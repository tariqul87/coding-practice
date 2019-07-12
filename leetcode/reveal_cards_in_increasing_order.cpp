#include <bits/stdc++.h>
using namespace std;

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);
void printDoubleIntArray(vector<vector<int>> array, string delemeter);

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        vector<int> result;

        result.push_back(deck[deck.size() - 1]);
        for (int i = deck.size() - 2; i >= 0; i--)
        {
            int lastIndex = result.size() - 1;
            int val = result[lastIndex];
            result.erase(result.begin() + lastIndex);
            result.insert(result.begin(), val);
            result.insert(result.begin(), deck[i]);
        }

        return result;
    }
};

int main(void)
{
    vector<int> array({17,13,11,2,3,5,7});
    Solution solution;
    printIntArray(solution.deckRevealedIncreasing(array), " ");
    return 0;
}

void printIntArray(vector<int> array, string delemeter)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << delemeter;
    }

    cout << endl;
}

void printDoubleIntArray(vector<vector<int>> array, string delemeter)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j] << delemeter;
        }
        cout << endl;
    }

    cout << endl;
}

void intArrayInput(int count, vector<int> &array)
{
    for (int i = 0; i < count; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }
}

void intArrayInputWithCount(vector<int> &array)
{
    int count;
    cin >> count;
    intArrayInput(count, array);
}