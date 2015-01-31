/*

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/


class Solution {
public:
    int reverse(int x) {
        const int maxInt = 2147483647;
        long long newX = x;
        bool symbol = true;
        if(x < 0){
          symbol = false;
          newX = -newX;
        } 
        
        long long ans = 0;
        while(0 != newX){
            ans = ans * 10 + newX % 10;
            newX = newX / 10;
            if(ans > maxInt) return 0;
        }
    
        if(!symbol) ans = -ans;
        
        return (int)ans;
    }

};