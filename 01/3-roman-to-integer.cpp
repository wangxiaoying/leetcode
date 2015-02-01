/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*/


class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> map_roman_int = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int before = 2000;
        int now = 0;
        
        for(int i = 0; i < s.length(); ++i){
            now = map_roman_int[s[i]];
            if(now <= before) ans += now;
            else ans = ans - 2* before + now;
            before = now;
        }
        
        return ans;
    }
};