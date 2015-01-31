/*

Determine whether an integer is a palindrome. Do this without extra space.

*/


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long y = 0;
        long num = x;
        
        while(0 != num){
            y = y * 10 + num % 10;
            num /= 10;
        }
        
        return y == x;
    }
};