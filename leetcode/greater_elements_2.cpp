#include <bits/stdc++.h>
using namespace std;

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> result, elements;
        if (nums.size() == 0)
        {
            return result;
        }
        int max = nums[0];
        elements.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                elements.push_back(nums[i]);
            }

            if (max < nums[i])
            {
                max = nums[i];
            }
        }

        cout << max << endl;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == max)
            {
                result.push_back(-1);
            }
            else
            {
                int j = 0;
                while (j < elements.size() && nums[i] >= elements[j])
                {
                    j++;
                }

                if (j == elements.size())
                {
                    result.push_back(-1);
                }
                else
                {
                    result.push_back(elements[j]);
                }
            }

            int j = 0;
            while (j < elements.size())
            {
                if (elements[j] <= nums[i])
                {
                    elements.erase(elements.begin() + j);
                }
                else
                {
                    j++;
                }
            }

            elements.insert(elements.begin(), nums[i]);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);

int main(void)
{
    vector<int> num1({5, 4, 3, 2, 1});
    // intArrayInputWithCount(num1);
    // intArrayInputWithCount(num2);

    Solution solution;
    printIntArray(solution.nextGreaterElements(num1), " ");
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