/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

class Solution {
public:
	void getLength(vector<int>& dp){
	    bool flag = false;
	    int length = 0;
	    for(int i = (int)dp.size()-1; i >= 0; --i){
	        if(dp[i] > 0){
 	           length += dp[i];
	            i -= (dp[i] * 2- 1);
	        }else if(flag || 0 == dp[i]){
	            break;
	        }else{
	            flag = true;
	            length++;
	        }
	    }
	    if(flag) dp.push_back(length);
	    else dp.push_back(0);
	}
	
    int longestValidParentheses(string s) {
        vector<int> dp;
        int ans = 0;
        
        for(int i = 0; i < s.length(); ++i){
            if('(' == s[i]) dp.push_back(-1);
            else getLength(dp);
            ans = max(ans, dp[i]);
        }
        
        return ans * 2;
    }
};