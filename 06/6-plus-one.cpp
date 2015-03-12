/*

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.empty()){
            digits.push_back(1);
            return digits;
        }
        
        reverse(digits.begin(), digits.end());
        int before = 1;
        for(int i = 0; i < digits.size(); ++i){
            digits[i] += before;
            if(digits[i] < 10){
                before = 0;
                break;
            } 
            before = 1;
            digits[i] -= 10;
        }
        if(before > 0) digits.push_back(before);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};