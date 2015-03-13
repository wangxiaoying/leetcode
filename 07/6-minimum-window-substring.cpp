/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/


class Solution {
public:
    string minWindow(string S, string T) {
        int s_len = (int)S.length(), t_len = (int)T.length();
        if(0 == s_len || 0 == t_len || s_len < t_len) return "";
        
        int neg_count = t_len;
        map<char, int> mp;
        for(int i = 0; i < t_len; ++i) mp[T[i]]--;
        
        string ans = S+S;
        int start = 0, tmp_len = 0;
        for(int i = 0; i < s_len; ++i){
            mp[S[i]]++;
            tmp_len++;
            if(mp[S[i]] <= 0) neg_count--;
            if(0 == neg_count){
                while(true){
                    mp[S[start]]--;
                    if(-1 == mp[S[start]]) break;
                    tmp_len--;
                    start++;
                }
                neg_count = 1;
                if(ans.length() > tmp_len) ans = S.substr(start, tmp_len);
                start++;
                tmp_len--;
            }
        }
        
        if(ans.length() > s_len) return "";
        return ans;
    }
};
