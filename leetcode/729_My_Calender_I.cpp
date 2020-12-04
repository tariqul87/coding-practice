#include "array.cpp"

class MyCalendar
{
public:
    vector<int> startTimes;
    vector<int> endTimes;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        if (startTimes.size() == 0 || endTimes.back() <= start)
        {
            startTimes.push_back(start);
            endTimes.push_back(end);

            return true;
        }

        vector<int>::iterator index = lower_bound(startTimes.begin(), startTimes.end(), start);
        int i = index - startTimes.begin();

        int left = i - 1, right = i;

        if (left >= 0 && endTimes.size() && endTimes[left] > start)
        {
            return false;
        }

        if (right < startTimes.size() && end > startTimes[right])
        {
            return false;
        }

        startTimes.insert(startTimes.begin() + i, start);
        endTimes.insert(endTimes.begin() + i, end);

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */