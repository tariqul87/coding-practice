#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getClosestValue(int target, int val1, int val2) {
        return abs(target - val1) < abs(target - val2) ? val1 : val2;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        
        for(int i=0; i<nums.size() - 2 && diff != 0; i++) {
            int low = i+1, high = nums.size() - 1;
            
            while(low < high) {
                int sum = nums[i]+nums[low]+nums[high];
                
                result = getClosestValue(target, result, sum);
                
                if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        
        return target - diff;    
    }
};

int main(void) {
    vector<int> nums = {-1, -4, 1, 2};
    int target = 1;
    
    Solution s;
    cout<<s.threeSumClosest(nums, target)<<endl;
    
	return 0;
}
