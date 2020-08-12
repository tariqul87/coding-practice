class Solution {
public:
	vector<int> getFrequencyVector(string str) {
		vector<int> frequency(26, 0);

		for(char ch: str) {
			frequency[ch - 'a']++;
		}

		return frequency;
	}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, int> keyIndex;
        vector<vector<string>> result;

        for(string str: strs) {
        	vector<int> key = getFrequencyVector(str);

        	if (keyIndex.find(key) == keyIndex.end()) {
        		keyIndex[key] = result.size();
        		result.push_back({});
        	}

        	result[keyIndex[key]].push_back(str);
        }

        return result;
    }
};