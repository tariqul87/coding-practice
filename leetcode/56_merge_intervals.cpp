#include "array.cpp"

bool comp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> result;

        for(vector<int> interval: intervals) {

        	if (result.size() && interval.front() <= result.back().back()) {
        		result.back()[1] = max(result.back().back(), interval[1]);
        	} else {
        		result.push_back(interval);
        	}
        }

        return result;

    }
};

int main(void) {
	vector<vector<int>> intervals = {{1, 4}, {4, 10}, {-2, 9}, {8,15}};
	Solution s;

	printDoubleIntArray(s.merge(intervals), " ");

	return 0;
}