#include "array.cpp"

class Solution
{
    int getNumberFromBits(vector<int> bits, int start, int end)
    {
        int power = 0, number = 0;
        for (int i = start; i >= end; i--)
        {
            if (bits[i])
            {
                number += pow(2, power);
            }
            power++;
        }

        return number;
    }
    void addIfTime(vector<int> &bits, vector<string> &result)
    {
        int hour = 0, minute = 0;
        string str = "";

        hour = getNumberFromBits(bits, 3, 0);
        if (hour > 12)
        {
            return;
        }
        else if (hour == 0)
        {
            str = "0:";
        }
        else
        {
            str = to_string(hour) + ":";
        }

        minute = getNumberFromBits(bits, 9, 4);
        if (minute > 59)
        {
            return;
        }
        else
        {
            str += minute < 10 ? "0" + to_string(minute) : to_string(minute);
        }

        result.push_back(str);
    }
    void calculateTime(int nums, int index, int size, int onBits, vector<int> &bits, vector<string> &result)
    {
        if (index == size)
        {
            if (nums == onBits)
            {
                addIfTime(bits, result);
            }
            return;
        }

        bits[index] = 0;
        calculateTime(nums, index + 1, size, onBits, bits, result);
        if (onBits < nums)
        {
            bits[index] = 1;
            calculateTime(nums, index + 1, size, onBits + 1, bits, result);
        }
    }

public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> result;
        vector<int> bits(10, 0);
        calculateTime(num, 0, 10, 0, bits, result);
        return result;
    }
};

int main(void)
{
    Solution solution;
    vector<string> result = solution.readBinaryWatch(1);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}