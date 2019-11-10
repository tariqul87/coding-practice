#include "array.cpp"

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> result(n, 0);

        for (int i = 0; i < bookings.size(); i++)
        {
            result[bookings[i][0] - 1] += bookings[i][2];
            result[bookings[i][1]] -= bookings[i][2];
        }

        for (int i = 1; i < result.size(); i++)
        {
            result[i] += result[i - 1];
        }

        return result;
    }
};

int main(void)
{
    Solution solution;
    vector<vector<int>> bookings = {{1, 2, 10},
                                    {2, 3, 20},
                                    {2, 5, 25}};
    printIntArray(solution.corpFlightBookings(bookings, 1), " ");

    return 0;
}