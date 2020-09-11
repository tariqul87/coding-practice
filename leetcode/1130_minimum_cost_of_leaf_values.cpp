class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int result = 0;
        
        for(int val: arr) {
            while(!st.empty() && st.top() <= val) {
                int lowValue = st.top();
                st.pop();
                result += lowValue * (st.empty() ? val : min(st.top(), val));
            }
            
            st.push(val);
        }
        
        while(st.size() > 1) {
            int val = st.top();
            st.pop();
            result += st.top() * val;
        }
        
        return result;
    }
};
