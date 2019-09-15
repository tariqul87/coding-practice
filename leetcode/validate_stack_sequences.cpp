#include "./array.cpp"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> result;
        for(int i=0; i<pushed.size(); i++) {
            result.push_back(pushed[i]);

            while(result.size() && result[result.size() - 1] == popped[0]) {
                // cout<<"result: "<<endl;
                // printIntArray(result, " ");
                // cout<<"popped: "<<endl;
                // printIntArray(popped, " ");
                result.erase(result.begin() + result.size() - 1);
                popped.erase(popped.begin());
            }
        }

        return popped.size() > 0 ? false : true;
    }
};

int main(void) {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};
    Solution solution;
    cout<<solution.validateStackSequences(pushed, popped)<<endl;

    return 0;
}