#include <bits/stdc++.h>
using namespace std;

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);
void printDoubleIntArray(vector<vector<int>> array, string delemeter);

class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        set<int> seen;
        int result;

        for (int i = 0; i < A.size(); i++)
        {
            if (seen.find(A[i]) != seen.end())
            {
                result = A[i];
                break;
            }
            else
            {
                seen.insert(A[i]);
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> array({1, 2, 3, 3});
    Solution solution;
    cout << solution.repeatedNTimes(array) << endl;
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