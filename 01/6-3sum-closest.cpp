/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() < 3) return 0;
        sort(num.begin(), num.end());
        
        int ans = num[0] + num[1] + num[2];
        for(int i = 0; i < num.size() - 2; ++i){
            if(i && num[i] == num[i-1]) continue;
            for(int j = i + 1, k = num.size() - 1; j < k; ){
                if(j > i + 1 && num[j] == num[j-1]){
                    j++;
                    continue;
                }
                if(k < num.size() - 1 && num[k] == num[k+1]){
                    k--;
                    continue;
                }
                int tmp = num[i] + num[j] + num[k];
                if(tmp == target) return target;
                else if(tmp < target) j++;
                else if(tmp > target) k--;
                if(abs(tmp - target) < abs(ans - target)) ans = tmp;
            }
        }
        
        return ans;
    }
};