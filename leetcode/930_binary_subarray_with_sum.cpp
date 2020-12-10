#include "array.cpp"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A, S) - atMost(A, S-1); 
    }
    
    int atMost(vector<int>& A, int S) {
        int currentSum = 0, result = 0, i = 0, n = A.size();
        
        for(int j=0; j<n; j++) {
            currentSum += A[j];
            
            while(currentSum > S && i <= j) {
                currentSum -= A[i++];
            }
            
            result += j - i + 1;
        }
        
        return result;
    }
};