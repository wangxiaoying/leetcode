/*

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/


class Solution {
public:
    void compute(vector<int> &S, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &flag, int remain, int begin){
        if(0 == remain) ans.push_back(temp);
        else{
            for(int i = begin; i < S.size(); ++i){
                if(flag[i]) continue;
                temp.push_back(S[i]);
                flag[i] = true;
                compute(S, ans, temp, flag, remain-1, i+1);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> flag(S.size(), false);
        
        sort(S.begin(), S.end());
        for(int i = 0; i <= S.size(); ++i){
            compute(S, ans, temp, flag, i, 0);
        }
        
        return ans;
    }
};