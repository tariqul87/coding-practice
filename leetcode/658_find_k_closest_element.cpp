#include "array.cpp"

class Solution
{
public:
    int findClosestIndex(vector<int> &arr, int target)
    {
        if (target <= arr.front())
        {
            return 0;
        }

        if (target >= arr.back())
        {
            return arr.size() - 1;
        }

        int low = 0, high = arr.size(), mid;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid > 0 && target < arr[mid - 1])
            {
                high = mid - 1;
            }
            else if (mid < arr.size() - 1 && target > arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                break;
            }
        }

        return abs(arr[mid - 1] - target) <= abs(arr[mid] - target) ? mid - 1 : mid;
    }
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int start = findClosestIndex(arr, x), size = arr.size();
        int end = start;

        while (end - start + 1 < k)
        {
            int leftDistance = start > 0 ? abs(arr[start - 1] - x) : INT_MAX;
            int rightDistance = end != size - 1 ? abs(arr[end + 1] - x) : INT_MAX;

            if (leftDistance <= rightDistance)
            {
                start--;
            }
            else
            {
                end++;
            }
        }

        vector<int> result;
        for (int i = start; i <= end; i++)
        {
            result.push_back(arr[i]);
        }

        return result;
    }
};

int main(void)
{
    vector<int> arr = {2, 3, 4};
    int k = 1, x = 3;
    Solution s;
    vector<int> result = s.findClosestElements(arr, k, x);

    printIntArray(result, " ");

    return 0;
}