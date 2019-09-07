#include <bits/stdc++.h>
#include "./template.cpp"
using namespace std;

// Soluition 1
/*
class Solution
{
public:
    void sortPeopleBySize(vector<vector<int>> &people)
    {
        for (int i = 0; i < people.size(); i++)
        {
            for (int j = i + 1; j < people.size(); j++)
            {
                if (people[i][0] < people[j][0] || (people[i][0] == people[j][0] && people[i][1] > people[j][1]))
                {
                    vector<int> person = people[i];
                    people[i] = people[j];
                    people[j] = person;
                }
            }
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> result;
        sortPeopleBySize(people);
        printDoubleIntArray(people, " ");
        cout << "******" << endl;

        while (people.size())
        {
            int seen_greater_elements = 0, i = 0;
            for (i = 0; i < result.size(); i++)
            {
                if (seen_greater_elements == people[0][1])
                {
                    break;
                }

                if (result[i][0] >= people[0][0])
                {
                    seen_greater_elements++;
                }
            }

            result.insert(result.begin() + i, people[0]);
            cout << "Values: " << people[0][0] << " " << people[0][1] << endl;
            printDoubleIntArray(result, " ");

            people.erase(people.begin());
        }

        return result;
    }
};
*/

// Solution 2
class Solution
{
public:
    static bool compareValues(vector<int> p1, vector<int> p2)
    {
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), compareValues);
        vector<vector<int>> result;

        for (int i = 0; i < people.size(); i++)
        {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};

int main(void)
{
    vector<vector<int>> queue({{9, 0}, {7, 0}, {1, 9}, {3, 0}, {2, 7}, {5, 3}, {6, 0}, {3, 4}, {6, 2}, {5, 2}});
    Solution solution;
    printDoubleIntArray(solution.reconstructQueue(queue), " ");

    return 0;
}