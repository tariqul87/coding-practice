#include "./array.cpp"

class Solution
{
public:
    int getTicketCostFromIndex(vector<int> &days, vector<int> &dayWiseCost, int index, int leftDays)
    {
        int nextDayIndex = index + 1;
        while (nextDayIndex < days.size() && days[nextDayIndex] < days[index] + leftDays)
        {
            nextDayIndex++;
        }
        return nextDayIndex == days.size() ? 0 : dayWiseCost[nextDayIndex];
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dayWiseCost(days.size(), 0);
        dayWiseCost[days.size() - 1] = min(costs[0], min(costs[1], costs[2]));

        for (int i = days.size() - 2; i >= 0; i--)
        {
            dayWiseCost[i] = costs[0] + dayWiseCost[i + 1];

            for (int j = 1; j < 3; j++)
            {
                dayWiseCost[i] = min(dayWiseCost[i], costs[j] + getTicketCostFromIndex(days, dayWiseCost, i, j == 1 ? 7 : 30));
            }
        }

        return dayWiseCost[0];
    }
};

int main(void)
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {7, 2, 15};

    Solution s;
    cout << s.mincostTickets(days, costs) << endl;
}