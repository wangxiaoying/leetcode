/*

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(0 == n) return 0; 
        
        int ans = n;
        for(int i = 0, j = 0; j < n; ++j){
            if(elem == A[j]) ans--;
            else A[i++] = A[j];
        }
        
        return ans;
    }
};