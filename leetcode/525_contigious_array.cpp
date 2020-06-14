#include "array.cpp"

class Solution
{
public:
    int getLastCountSeenIndex(unordered_map<int, int> &seen, int count)
    {
        if (seen.find(count) != seen.end() && seen.find(-count) != seen.end())
        {
            return min(seen[count], seen[-count]);
        }

        if (seen.find(count) != seen.end())
        {
            return seen[count];
        }

        if (seen.find(-count) != seen.end())
        {
            return seen[-count];
        }

        return INT_MIN;
    }
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> seen;
        seen[0] = -1;
        int count = 0, result = 0, index = 0;

        while (index < nums.size())
        {
            count += (nums[index] == 1 ? 1 : -1);
            int sameCountSeenIndex = getLastCountSeenIndex(seen, count);

            if (sameCountSeenIndex >= -1)
            {
                result = max(result, index - sameCountSeenIndex);
            }

            if (seen.find(count) == seen.end())
            {
                seen[count] = index;
            }

            index++;
        }

        return result;
    }
};

int main(void)
{
    vector<int> arr = {0, 0, 1, 0, 0, 0, 1, 1};
    Solution s;

    cout << s.findMaxLength(arr) << endl;

    return 0;
}