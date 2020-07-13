class Solution {
public:
    unordered_map<int, vector<string>> wordMap;
    vector<string> wordBreak(string s, int start, unordered_set<string>& wordSet) {
        if (start == s.size()) {
            return {};
        }
        
        if (wordMap.find(start) != wordMap.end()) {
            return wordMap[start];
        }
        
        vector<string> result = {};
        
        string wholeText = s.substr(start, s.size() - start + 1);
        
        if (wordSet.find(wholeText) != wordSet.end()) {
            result.push_back(wholeText);
        }
        
        for(int i=1; start + i <= s.size(); i++) {
            string str = s.substr(start, i);
            
            if (wordSet.find(str) != wordSet.end()) {
                vector<string> nextWordBreaks = wordBreak(s, start+i, wordSet);
                
                for(string nextWordBreak : nextWordBreaks) {
                    result.push_back(str + " " + nextWordBreak);
                }
            }
        }
        
        wordMap[start] = result;
        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); 
        
        return wordBreak(s, 0, wordSet);
    }
};