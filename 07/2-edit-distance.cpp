/*

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/


class Solution {
public:
    inline int min3(int a, int b, int c){
        return min(a, min(b, c));
    }
    
    int minDistance(string word1, string word2) {
        const int len1 = (int)word1.length();
        const int len2 = (int)word2.length();
        
        int dp[len1+1][len2+1];
        dp[0][0] = 0;
        for(int i = 1; i <= len1; ++i) dp[i][0] = i;
        for(int i = 1; i <= len2; ++i) dp[0][i] = i;
        
        int replace, insert, remove;
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                replace = dp[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0 : 1);
                insert = dp[i][j-1]+1;
                remove = dp[i-1][j]+1;
                dp[i][j] = min3(replace, insert, remove);
            }
        }
        
        return dp[len1][len2];
    }
};
