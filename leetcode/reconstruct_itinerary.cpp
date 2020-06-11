#include "array.cpp"

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, vector<string>> fromToMap;

        for (int i = 0; i < tickets.size(); i++)
        {
            string from = tickets[i][0];
            string to = tickets[i][1];

            if (fromToMap.find(from) == fromToMap.end())
            {
                fromToMap[from] = {};
            }
            
            int index = 0;
            while (index < fromToMap[from].size() && to >= fromToMap[from][index]) {
                index++;
            }

            fromToMap[from].insert(fromToMap[from].begin() + index, to);
            cout<<from<<": ";
            for(int i=0; i<fromToMap[from].size(); i++) {
                cout<<fromToMap[from][i]<<"->";
            }

            cout<<endl;
        }

        vector<string> result;
        return result;

    }
};

int main(void)
{
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution solution;
    vector<string> result = solution.findItinerary(tickets);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}