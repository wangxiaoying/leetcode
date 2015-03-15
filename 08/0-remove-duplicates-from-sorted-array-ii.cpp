/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;
        int i, j;
        for(i = 2, j = 2; i < n; ++i){
            if(A[j-2] != A[i]){
                A[j] = A[i];
                j++;
            }
        }
        return j;
    }
};