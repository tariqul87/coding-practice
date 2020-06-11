#include "array.cpp"

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return 0;
        }

        vector<int> start, end;

        for (vector<int> interval : intervals)
        {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int count = 0, j = 0;

        for (int i = 0; i < start.size(); i++)
        {
            if (start[i] >= end[j])
            {
                j++;
            }
            else
            {
                count++;
            }
        }

        return count;
    }
};

int main(void)
{
    vector<vector<int>> intervals = {{1, 5}, {8, 9}, {8, 9}};
    Solution s;
    cout << s.minMeetingRooms(intervals) << endl;
    return 0;
}