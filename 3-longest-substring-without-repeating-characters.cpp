#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <=1) return s.length();
        
        map<char, int> index;
        vector<int> dp;
        index[s[0]] = 1;
        dp.push_back(1);
        int last = 0;
        
        int ans = 1;
        
        for(int i = 1; i < s.length(); ++i){
            if(0 == index[s[i]]){
                dp.push_back(dp[i-1] + 1);
            }else{
                last = max(index[s[i]], last);
                dp.push_back(i - last + 1);
            }
            index[s[i]] = i + 1;
            if(dp[i] > ans) ans = dp[i];
        }
        
        return ans;
    }
};