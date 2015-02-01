/*

Write a function to find the longest common prefix string amongst an array of strings.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans = "";
        if(0 == strs.size()) return ans;
        if(1 == strs.size()) return strs[0];
        
        int pos = 0;
        while(true){
            if('\0' == strs[0][pos]) break;
            char now = strs[0][pos];
            bool flag = true;
            for(int i = 1; flag && i < strs.size(); ++i){
                if('\0' == strs[i][pos] || strs[i][pos] != now) flag = false;
            }
            if(!flag) break;
            ans += now;
            pos++;
        }
        
        return ans;
    }
};