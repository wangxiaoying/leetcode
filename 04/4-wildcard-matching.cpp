/*

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

*/


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const int len_s = strlen(s), len_p = strlen(p);
        
        if(len_s > 3000 || len_p > 3000) return false;
        
        vector<vector<bool>> dp;
        for(int i = 0; i <= len_s; ++i){
            vector<bool> tmp(len_p+1, false);
            dp.push_back(tmp);
        }

        int index = 0;
        while(index <= len_p && (0 == index || '*' == p[index-1])){
            dp[0][index] = true;
            index++;
        }
        
        for(int i = 1; i <= len_s; ++i){
            for(int j = 1; j <= len_p; ++j){
                if('*' == p[j-1]){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || '?' == p[j-1]);
                }
            }
        }
        return dp[len_s][len_p];
    }
};