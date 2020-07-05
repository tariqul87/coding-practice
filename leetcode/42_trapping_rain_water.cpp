class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        
        int left = 0, right = height.size() - 1, count = 0;
        int maxLeft = 0, maxRight = 0;
        
        while(left < right) {
            if (height[left] < height[right]) {
                int val = maxLeft - height[left];
                count += (val <= 0 ? 0 : val);
                maxLeft = max(maxLeft, height[left]);
                left++;
            } else {
                int val = maxRight - height[right];
                count += (val <= 0 ? 0 : val);
                maxRight = max(maxRight, height[right]);
                right--;
            }
        }
        
        return count;
    }
};
