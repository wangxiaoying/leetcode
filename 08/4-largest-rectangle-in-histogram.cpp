/*

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty()) return 0;
        
        int ans = 0;
        vector<int> stack;
        
        height.push_back(0);
        for(int i = 0; i < height.size(); ++i){
            while(!stack.empty() && height[stack.back()] >= height[i]){
                int h = height[stack.back()];
                stack.pop_back();
                
                int index1 = -1;
                if(!stack.empty()) index1 = stack.back();
                
                int s = h*(i-index1-1);
                ans = max(s, ans);
            }
            stack.push_back(i);
        }
        
        return ans;
    }
};