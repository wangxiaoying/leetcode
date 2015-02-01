/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(NULL == s || NULL == p || *p == '*') return false;
        if('\0' == *p) return *s == '\0';
        
        if(*(p+1) != '*'){
            if('\0' == *s) return false;
            if(*p != '.' && *p != *s) return false;
            return isMatch(s+1, p+1);
        }
        
        while(('.' == *p && '\0' != *s) || *s == *p){
            if(isMatch(s, p+2)) return true;
            s++;
        }
        
       return isMatch(s, p+2);
    }
};