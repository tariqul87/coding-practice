//medium problem: 540
#include "array.cpp"

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<vector<int>> frequency;
        map<char, int> frequencyMap;

        for(int i=0; i<s.size(); i++) {
            if (frequencyMap.find(s[i]) == frequencyMap.end()) {
                frequencyMap[s[i]] = 1;
            } else {
                frequencyMap[s[i]]++;
            }
        }

        for(auto start = frequencyMap.begin(); start != frequencyMap.end(); start++) {
            frequency.push_back({start->first, start->second});
        }

        sort(frequency.begin(), frequency.end(), [](vector<int> a, vector<int> b) {
            return a[1] > b[1];
        });

        string result = "";
        
        for (int i=0; i<frequency.size(); i++) {
            while(frequency[i][1] > 0) {
                result += (char)(frequency[i][0]);
                frequency[i][1]--;
            }
        }
        return result;
    }
};

int main(void)
{
    string str = "Aabb";

    Solution solution;
    cout << solution.frequencySort(str) << endl;

    return 0;
}