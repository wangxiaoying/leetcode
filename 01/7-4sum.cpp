/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ans;
        if(num.size() < 4) return ans;
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size()-3; ++i){
            if(i && num[i] == num[i-1]) continue;
            for(int j = i+1; j < num.size()-2; ++j){
                if(j > i+1 && num[j] == num[j-1]) continue;
                for(int k = j+1, l = num.size()-1; k < l; ){
                    if(k > j+1 && num[k] == num[k-1]){
                        k++;
                        continue;
                    }
                    if(l < num.size()-1 && num[l] == num[l+1]){
                        l--;
                        continue;
                    }
                    int tmp = num[i] + num[j] + num[k] + num[l];
                    if(target == tmp){
                        ans.push_back({num[i], num[j], num[k], num[l]});
                        k++;
                        l--;
                    }else if(target > tmp){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};