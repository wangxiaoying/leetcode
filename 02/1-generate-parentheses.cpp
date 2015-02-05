/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

class Solution {
public:
    void generateString(string s, int sum, vector<string> &ans, int n_remain){
        if(0 == n_remain){
            for(int i = 0; i < sum; ++i) s += ')';
            ans.push_back(s);
            return;
        }
        
        if(sum > 0){
            generateString(s+")", sum-1, ans, n_remain);
        }
        generateString(s+"(", sum+1, ans, n_remain-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        generateString("", 0, ans, n);
        
        return ans;
    }
};