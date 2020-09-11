class Solution {
public:
    unordered_map<string, vector<string>> successorMap;
    unordered_map<string, int> resultMap;
    void generateSuccessors(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_map<string, unordered_set<string>> seen;
        
        for(string str: words) {
            for(int i=0; i<str.size(); i++) {
                string prefix = i == 0 ? "" : str.substr(0, i);
                string suffix = i == str.size() - 1 ? "" : str.substr(i+1, str.size() - i - 1);
                string pre = prefix + suffix;
                
                if (wordSet.find(pre) != wordSet.end() 
                    && (seen.find(pre) == seen.end() || seen[pre].find(str) == seen[pre].end())) {
                    successorMap[pre].push_back(str);
                    seen[pre].insert(str);
                }
            }
        }
    }
    int getChainLength(string word) {
        if (resultMap.find(word) != resultMap.end()) {
            return resultMap[word];
        }
        
        int result = 0;
        for(string successor: successorMap[word]) {
            result = max(result, 1 + getChainLength(successor));
        }
        
        resultMap[word] = result;
        return result;
    }
    int longestStrChain(vector<string>& words) {
        generateSuccessors(words);
        
        int result = 0;
        for(string word: words) {
            int currentResult = 1+getChainLength(word);
            // cout<<word<<": "<<currentResult<<endl;
            result = max(result, currentResult);
        }
        
        return result;
    }
};