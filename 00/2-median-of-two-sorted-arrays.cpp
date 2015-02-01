/*

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/

#include <algorithm>

class Solution {
public:
	int binarySearch(int A[], int m, int B[], int n, int l, int r){
		if(r - l <= 0) return l;

		int i = (l + r) / 2;
		int j = (m + n) / 2 - i;

		if(i != 0 && j != n && A[i-1] > B[j]){
			return binarySearch(A, m, B, n, l, i-1);
		}else if(j != 0 && i != m && B[j-1] > A[i]){
			return binarySearch(A, m, B, n, i+1, r);
		}

		return i;
	}

	double getMedianInOne(int A[], int m){
		double mid = (double)A[m/2];
		if( 0 == m % 2){
			mid = (mid + (double)A[m/2-1]) / 2;
		}
		return mid;
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(0 == m + n) return 0;
        if(0 == m) return getMedianInOne(B, n);
        if(0 == n) return getMedianInOne(A, m);

        int sum = (m + n) / 2;
        int i, j;
        double mid;

        if(m >= n){
        	i = binarySearch(A, m, B, n, (m-n)/2, sum);
        	j = sum - i;
        }else{
        	j = binarySearch(B, n, A, m, (n-m)/2, sum);
        	i = sum - j;
        }

        if(m == i){
        	mid = B[j];
        }else if(n == j){
        	mid = A[i];
        }else{
        	mid = min(A[i], B[j]);
        }

        if(0 == (m + n) % 2){
        	if(0 == i){
        		mid = (mid + B[j-1]) / 2;
        	}else if(0 == j){
        		mid = (mid + A[i-1]) / 2;
        	}else{
        		mid = (mid + max(A[i-1], B[j-1])) / 2;
        	}
        }

        return mid;
    }
};