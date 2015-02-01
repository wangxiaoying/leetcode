/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        if(1 >= height.size()) return 0;
        int left = 0, right = height.size()-1;
        int ans = 0;
        
        while(left < right){
            ans = max(ans, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]){
                int i = left + 1;
                while(i < height.size() && height[i] <= height[left]) i++;
                left = i;
            }else{
                int i = right - 1;
                while(i >= 0 && height[i] <= height[right]) i--;
                right = i;
            }
        }
        
        return ans;
    }
};