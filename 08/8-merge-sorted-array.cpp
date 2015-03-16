/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

*/


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for(int i = m-1; i >=0; --i) A[n+i] = A[i];
        
        int i = n, j = 0, k = 0;
        while(i < (m+n) && j < n){
            if(A[i] < B[j]) A[k++] = A[i++];
            else A[k++] = B[j++];
        }
        
        while(i < (m+n)) A[k++] = A[i++];
        while(j < n) A[k++] = B[j++];
    }
};