/*

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

class Solution {
public:
void compute(vector<int> &num, vector<vector<int>> &ans, vector<bool> &flags, vector<int> &temp){
    if(temp.size() == num.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < num.size(); ++i){
        if(flags[i]) continue;
        temp.push_back(num[i]);
        flags[i] = true;
        compute(num, ans, flags, temp);
        flags[i] = false;
        temp.pop_back();
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> ans;
    vector<bool> flags(num.size(), false);
    
    compute(num, ans, flags, *new vector<int>());
    return ans;
}
};