/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/


class Solution {
public:
	int maxSubArray(int A[], int n) {
		if(0 == n) return 0;
		
		vector<int> dp;
		int ans;
		
		for(int i = 0; i < n; ++i){
			if(i && dp[i-1] > 0){
				dp.push_back(dp[i-1] + A[i]);
			}else{
				dp.push_back(A[i]);
			}
		}
		
		ans = dp[0];
		for(int i = 1; i < n; ++i){
			if(ans < dp[i]) ans= dp[i];
		}
		
		return ans;
	}

};