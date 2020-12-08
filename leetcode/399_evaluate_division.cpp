#include "array.cpp"

class Solution {
public:
    unordered_set<string> seenVariables;
    unordered_map<string, double> valueMap;
    unordered_map<string, vector<vector<string>>> equationMap;
    unordered_set<string> seen;
    string getEquationToken(string top, string bottom) {
        return top + "/" + bottom;
    }
    void updateEquationValue(string top, string bottom, double value) {
        string equationToken = top + "/" + bottom;
        seenVariables.insert(top);
        seenVariables.insert(bottom);
        
        if (seen.find(equationToken) != seen.end()) {
            return;
        }
        
        seen.insert(equationToken);
        valueMap[equationToken] = value;
        equationMap[top].push_back({top, bottom});
    }
    void updateEquationsValue(vector<vector<string>>& equations, vector<double>& values) {
        for(int i=0; i<equations.size(); i++) {
            string top = equations[i][0], bottom = equations[i][1];
            double value = values[i];
            
            updateEquationValue(top, bottom, value);
            
            if (value != 0.0) {
                updateEquationValue(bottom, top, 1/value);
            }
        }
    }
    double dfs(string top, string bottom, unordered_set<string>& seen) {
        if (top == bottom) {
            return seenVariables.find(top) != seenVariables.end() 
                && seenVariables.find(bottom) != seenVariables.end() ? 1 : -1;
        }
        
        string equationToken = getEquationToken(top, bottom);
        if (valueMap.find(equationToken) != valueMap.end()) {
            return valueMap[equationToken];
        }
        
        for(vector<string> equation: equationMap[top]) {
            string leftToken = getEquationToken(equation[0], equation[1]);
            string rightToken = getEquationToken(equation[1], bottom);
            if (seen.find(rightToken) != seen.end()) {
                continue;
            }
            
            seen.insert(rightToken);
            double currentValue = dfs(equation[1], bottom, seen);
            
            if (currentValue != -1) {
                valueMap[equationToken] = valueMap[leftToken] * currentValue;
                return valueMap[equationToken];
            }
        }
        
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        updateEquationsValue(equations, values);
        vector<double> result;
        
        for(vector<string> equation: queries) {
            unordered_set<string> seen;
            result.push_back(dfs(equation[0], equation[1], seen));
        }
        
        return result;
    }
};












