#include "array.cpp"

class Solution {
public:
    int getMax(vector<int> arr, int multiplier) {
        int index = arr.size() - 1;
        long lastSeenMax = arr[index];
        index--;
        
        while (index >= 0 && arr[index]*multiplier > lastSeenMax) {
            index--;
        }
        
        long long result = index == 0 ? arr[0] * multiplier : arr[index+1] * multiplier;

        if (result >= INT_MAX || result < 0) {
            return INT_MAX;
        }

        return (int)(result);
    }
    int nthUglyNumber(int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
        while(arr.size() < n) {
            cout<<arr.size()<<endl;
            int index = arr.size() - 1;
            int num2 = getMax(arr, 2);
            int num3 = getMax(arr, 3);
            int num5 = getMax(arr, 5);
            // cout<<num2<<" "<<num3<<" "<<num5<<endl;
            
            arr.push_back(min(min(num2, num3), num5));
        }
        
        return arr[n - 1];
    }
};

int main() {
    Solution solution;
    cout<<solution.nthUglyNumber(1690)<<endl;
    return 0;
}