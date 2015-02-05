/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isTempValid(string &s, stack<char> &stk, int pos){
        if(s.length() == pos){
            if(stk.empty())  return true;
            else return false;
        }
        
        char tmp = s[pos];
        switch(tmp){
            case '(': 
            case '{':
            case '[':
                stk.push(tmp); 
                break;
            case ')':
                if(stk.empty() || stk.top() != '(') return false;
                stk.pop();
                break;
            case '}':
                if(stk.empty() || stk.top() != '{') return false;
                stk.pop();
                break;
            case ']':
                if(stk.empty() || stk.top() != '[') return false;
                stk.pop();
                break;
            default:
                return false;
        }
        return isTempValid(s, stk, pos+1);
    }
    
    bool isValid(string s) {
        stack<char> stk;
        
        return isTempValid(s, stk, 0);
    }
};