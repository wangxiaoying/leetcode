/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/


class Solution {
public:
    string addBinary(string a, string b) {
        if("" == a) return b;
        if("" == b) return a;
        
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int length_a = a.length();
        int length_b = b.length();
        
        while(length_a < length_b){
            a += "0";
            length_a++;
        }
        while(length_b < length_a){
            b += "0";
            length_b++;
        }
        
        int temp = 0, now;
        for(int i = 0; i < length_a; ++i){
            now = (a[i]-'0') + (b[i]-'0') + temp;
            temp = now / 2;
            now = now % 2;
            ans += ('0'+now);
        }
        
        if(temp > 0){
            ans += '1';
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};