#include <bits/stdc++.h>
using namespace std;
// Normal solution
// class Solution
// {
// public:
//     vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> nextElements(nums2.size(), -1);

//         for (int i = nums2.size() - 2; i >= 0; i--)
//         {
//             int j = i + 1;
//             bool elementFound = true;

//             while (nums2[i] >= nums2[j])
//             {
//                 if (j >= nums2.size() || nextElements[j] == -1)
//                 {
//                     elementFound = false;
//                     break;
//                 }
//                 j++;
//             }

//             if (elementFound)
//             {
//                 nextElements[i] = nums2[j];
//             }
//         }

//         vector<int> result;
//         for (int i = 0; i < nums1.size(); i++)
//         {
//             for (int j = 0; j < nums2.size(); j++)
//             {
//                 if (nums1[i] == nums2[j])
//                 {
//                     result.push_back(nextElements[j]);
//                 }
//             }
//         }

//         return result;
//     }
// };

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> numberToNextNumber;
        vector<int> elements, result;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (elements.size())
            {
                if (nums2[i] >= elements[0])
                {
                    elements.erase(elements.begin());
                }
                else
                {
                    break;
                }
            }

            if (elements.size())
            {
                numberToNextNumber[nums2[i]] = elements[0];
            }
            else
            {
                numberToNextNumber[nums2[i]] = -1;
            }

            elements.insert(elements.begin(), nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            result.push_back(numberToNextNumber[nums1[i]]);
        }

        return result;
    }
};

void intArrayInput(int count, vector<int> &array);
void intArrayInputWithCount(vector<int> &array);
void printIntArray(vector<int> array, string delemeter);

int main(void)
{
    vector<int> num1({4, 1, 2}), num2({1, 3, 4, 2});
    // intArrayInputWithCount(num1);
    // intArrayInputWithCount(num2);

    Solution solution;
    printIntArray(solution.nextGreaterElement(num1, num2), " ");
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