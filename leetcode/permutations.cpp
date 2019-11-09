// // medium, #46
#include "array.cpp"
// heap's algo
// class Solution
// {
//     vector<vector<int>> permutations;

// public:
//     void generatePermutations(vector<int> arr, int size)
//     {
//         if (size == 1)
//         {
//             permutations.push_back(arr);
//             return;
//         }

//         for (int i = 0; i < size; i++)
//         {
//             generatePermutations(arr, size - 1);
//             if (size % 2 == 0)
//             {
//                 swap(arr[0], arr[size - 1]);
//             }
//             else
//             {
//                 swap(arr[i], arr[size - 1]);
//             }
//         }
//     }
//     void generateSerialPermulations(vector<int> arr) {

//     }
//     vector<vector<int>> permute(vector<int> &arr)
//     {
//         generatePermutations(arr, arr.size());
//         return permutations;
//     }
// };

// serail wise
class Solution
{
public:
    void generatePermutations(vector<int> &arr, int start, vector<vector<int>> &result)
    {
        if (start >= arr.size())
        {
            result.push_back(arr);
            return;
        }
        for (int i = start; i < arr.size(); i++)
        {
            swap(arr[start], arr[i]);
            generatePermutations(arr, start + 1, result);
            swap(arr[start], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &arr)
    {
        vector<vector<int>> result;
        generatePermutations(arr, 0, result);
        return result;
    }
};

int main(void)
{
    vector<int> arr = {1, 2, 3};
    Solution solution;
    printDoubleIntArray(solution.permute(arr), " ");

    return 0;
}