class Solution {
public:
    unordered_map<string, pair<string, int>> emailMap;
    int getBaseValue(unordered_map<int, int>& uf, int value) {
        while(uf.find(value) != uf.end() && uf[value] != value) {
            value = uf[value];
        }
        
        return value;
    }
    void updateBaseValue(unordered_map<int, int>& uf, int base, int value) {
        while(uf.find(base) != uf.end() && uf[base] != base) {
            int temp = uf[base];
            uf[base] = value;
            base = temp;
        }
        
        uf[base] = value;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int count = 0;
        vector<string> emails;
        unordered_set<string> emailSet;
        unordered_map<int, int> uf;
        
        for(vector<string> account: accounts) {
            string name = account.front();
            for(int i=1; i<account.size(); i++) {
                string email = account[i];
                
                if (emailMap.find(email) != emailMap.end()) {
                    if (emailMap[email].second != count) {
                        updateBaseValue(uf, emailMap[email].second, count);
                    }
                } else {
                    emailMap[email] = make_pair(name, count);
                }
                
                emails.push_back(email);
            }
            uf[count] = count;
            count++;
        }
        
        count = 0;
        sort(emails.begin(), emails.end());
        unordered_map<int, int> indexMap;
        vector<vector<string>> result;
        
        for(string email: emails) {
            if (emailSet.find(email) == emailSet.end()) {
                int base = getBaseValue(uf, emailMap[email].second);
                if (indexMap.find(base) == indexMap.end()) {
                    result.push_back({emailMap[email].first});
                    indexMap[base] = count;
                    count++;
                }
                result[indexMap[base]].push_back(email);
                emailSet.insert(email);
            }
        }
        
        return result;
    }
};