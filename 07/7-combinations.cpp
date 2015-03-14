/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/


class Solution {
public:
    void compute(vector<vector<int>> &ans, vector<int> &temp, vector<bool> &flag, int n, int k, int begin){
        if(0 == k) ans.push_back(temp);
        else{
            for(int i = begin; i <= n; ++i){
                if(flag[i]) continue;
                temp.push_back(i);
                flag[i] = true;
                compute(ans, temp, flag, n, k-1, i+1);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> flag(n+1, false);
        
        if(n <= 0 || k <= 0) return ans;
        
        compute(ans, temp, flag, n, k, 1);
        return ans;
    }
};