/*

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
       bool symbol = dividend > 0 ^ divisor >0 ? false : true;
       
       long long ldividend = abs((long long)dividend);
       long long ldivisor = abs((long long)divisor);
       long long ans = 0;
       
       for(int i = 31; i >= 0; --i){
           if(ldividend >= (ldivisor<<i)){
               ans |= 1LL<<i;
               ldividend -= (ldivisor<<i);
           }
       }
       
       if(!symbol) ans = -ans;
       
       return ans >= INT_MAX ? INT_MAX : ans <= INT_MIN ? INT_MIN : (int)ans;
    }
};