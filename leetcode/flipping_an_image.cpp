#include <bits/stdc++.h>
using namespace std;

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);
void printDoubleIntArray(vector<vector<int>> array, string delemeter);

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        vector<vector<int>> result;
        int i = 0;
        while (i < A.size())
        {
            vector<int> row;
            for (int j = A[i].size() - 1; j >= 0; j--)
            {
                row.push_back(A[i][j] == 0 ? 1 : 0);
            }
            result.push_back(row);
            i++;
        }

        return result;
    }
};

int main(void)
{
    vector<vector<int>> image({{1, 1, 0}, {1, 0, 1}, {0, 0, 0}});
    Solution solution;
    vector<vector<int>> result = solution.flipAndInvertImage(image);
    printDoubleIntArray(result, " ");
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