/*

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/

class Solution {
public:
    string intToRoman(int num) {
        const int COUNT = 13;
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        int iter = 0;
        
        for(int i = 0; i < COUNT && num > 0; ++i){
            int tmp = num / values[i];
            if(0 == tmp) continue;
            for(int j = 0; j < tmp; ++j){
                ans += romans[i];
            }
            num -= values[i] * tmp;
        }
        
        return ans;
    }
};