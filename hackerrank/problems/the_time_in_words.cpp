#include <bits/stdc++.h>
using namespace std;

string get_time(int hour, int minutes)
{
    vector<string> numbers = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"};

    string result = numbers[hour];
    result.append(" ");

    if (minutes == 0)
    {
        result.append("o' clock");
    }
    else if (minutes == 15)
    {
        result = "quarter past ";
        result.append(numbers[hour]);
    }
    else if (minutes < 30)
    {
        result = numbers[minutes];
        result.append(minutes > 1 ? " minutes " : " minute ");
        result.append("past ");
        result.append(numbers[hour]);
    }
    else if (minutes == 30)
    {
        result = "half past ";
        result.append(numbers[hour]);
    }
    else if (minutes == 45)
    {
        result = "quarter to ";
        result.append(numbers[(hour + 1) % 12]);
    }
    else
    {
        result = numbers[60 - minutes];
        result.append(" minutes to ");
        result.append(numbers[(hour + 1) % 12]);
    }

    return result;
}

int main(void)
{
    int hour, minutes;
    cin >> hour;
    cin >> minutes;
    cout << get_time(hour, minutes) << endl;
    return 0;
}