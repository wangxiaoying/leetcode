/*

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

*/


class Solution {
public:
	int atoi(const char *str) {
		const int MAX = 2147483647;
		const int MIN = -2147483648;
		const long long ABS_MIN = 2147483648;
		long long ans = 0;
		bool isPos = true;
		bool isNumber = false;

		for(int i = 0; str[i] != '\0'; ++i){
			if(str[i] >= '0' && str[i] <= '9'){
				ans = ans * 10 + str[i] - '0';
				if(isPos && ans >= MAX) return MAX;
				if(!isPos && ans >= ABS_MIN) return MIN;
			}else{
				if(isNumber) break;
				if(' ' == str[i]) continue;
				if('-' == str[i]){
					isPos = false;
				}else if('+' != str[i]){
					return 0;
				}
			}
			isNumber = true;
		}

		if(!isPos) ans = -ans;
		return (int)ans;
	}
};