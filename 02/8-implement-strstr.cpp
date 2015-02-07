/*

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

class Solution {
public:

    int strStr(char *haystack, char *needle) {
        int lh = strlen(haystack);
        int ln = strlen(needle);
        if(0 == ln) return 0;
        
        for(int i = 0; i < lh - ln + 1; ++i){
            int j = 0, k = i;
            for(; j < ln; ++j, ++k){
                if(*(haystack+k) != *(needle+j)) break;
            }
            if(ln == j) return i;
        }
        
        return -1;
    }
};