#include "./array.cpp"

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        vector<int> result(A.size(), 0);
        int even = 0;
        int odd = 1;
        
        for(int i=0; i<A.size(); i++) {
            if (A[i] % 2 == 0) {
                result[even] = A[i];
                even +=2; 
            } else {
                result[odd] = A[i];
                odd += 2;
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> arr({4, 2, 5, 7});
    Solution solution;
    printIntArray(solution.sortArrayByParityII(arr), " ");
    return 0;
}