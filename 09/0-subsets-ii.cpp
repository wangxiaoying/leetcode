/*

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> ans;
        ans.push_back({});
        sort(S.begin(), S.end());
        
        for(int i = 0; i < S.size(); ++i){
            int count = 1;
            while(i < S.size()-1 && S[i] == S[i+1]){
                count++;
                i++;
            }
            
            int size = (int)ans.size();
            for(int j = 0; j < size; ++j){
                vector<int> v1 = ans[j];
                int c = count;
                while(c){
                    vector<int> v2 = v1;
                    v2.push_back(S[i]);
                    ans.push_back(v2);
                    v1 = v2;
                    c--;
                }
            }   
        }
        return ans;
    }
    
};