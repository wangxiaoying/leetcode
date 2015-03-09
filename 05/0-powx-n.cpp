/*

Implement pow(x, n).

*/


class Solution {
public:
	double positivePow(double x, int n){
		if(1 == x) return 1;
		double ans = 1;
		while(n && ans != 0){
			ans *= x;
			n--;
		}
		return ans;
	}

	double pow(double x, int n) {
		if(0 == x) return 0;
		if(0 == n) return 1;
		
		double ans;
		bool x_ispos = x > 0 ? true : false;
		bool n_ispos = n > 0 ? true : false;
		
		if(!x_ispos) x = -x;
		if(!n_ispos) n = -n;
		
		ans = positivePow(x, n);
		
		if(!n_ispos) ans = 1 / ans;
		if(!x_ispos && 1==n%2) ans = -ans;
		
		return ans;
	}
};