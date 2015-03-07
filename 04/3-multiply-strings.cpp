/*

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        const int len1 = num1.length(), len2 = num2.length();
        vector<int> v_ans(len1+len2, 0);
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                v_ans[i+j] += (num1[i]-'0')*(num2[j]-'0');
                v_ans[i+j+1] += v_ans[i+j]/10;
                v_ans[i+j] %= 10;
            }
        }
        
        int index = len1+len2-1;
        while(index > 0 && 0 == v_ans[index]) index--;
        while(index >= 0){
            ans += '0'+v_ans[index];
            index--;
        }
        
        return ans;
    }
};