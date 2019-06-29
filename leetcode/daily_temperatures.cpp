#include <bits/stdc++.h>
using namespace std;

// hash implementation
// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         /* <value, index> pair */
//         map<int, int> tempToWaitDays;
//         vector<int> waitDays(temperatures.size(), 0);
//         map<int, int>::iterator it1, it2;

//         int max = temperatures[temperatures.size() - 1];
//         tempToWaitDays[max] = temperatures.size() - 1;

//         for (int i = temperatures.size() - 2; i >= 0; i--)
//         {
//             int temperature = temperatures[i];

//             if (temperature > max)
//             {
//                 max = temperature;
//                 tempToWaitDays[max] = i;
//             }
//             else
//             {
//                 int minDays = 30001;
//                 for (map<int, int>::iterator it = tempToWaitDays.begin(); it != tempToWaitDays.end(); it++)
//                 {
//                     if (it->first > temperature && it->second - i <= minDays)
//                     {
//                         minDays = it->second - i;
//                     }
//                 }
//                 waitDays[i] = minDays == 30001 ? 0 : minDays;
//             }

//             tempToWaitDays[temperature] = i;
//         }

//         return waitDays;
//     }
// };

// normal implementation
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> waitDays(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; i--)
        {
            int j = i + 1;
            bool highValue = true;
            while (j < temperatures.size() && temperatures[i] >= temperatures[j])
            {
                if (waitDays[j] == 0)
                {
                    highValue = false;
                    break;
                }
                j++;
            }

            if (highValue)
            {
                waitDays[i] = j - i;
            }
        }
        return waitDays;
    }
};

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);

int main(void)
{
    vector<int> temperatures({73,74,75,71,69,72,76,73});
    // vector<int> temperatures;
    // intArrayInputWithCount(temperatures);
    Solution solution;
    printIntArray(solution.dailyTemperatures(temperatures), " ");
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