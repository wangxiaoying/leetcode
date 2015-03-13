/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

*/


class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        vector<string> vstack;
        
        path += "/";
        for(int i = 0; i < path.length(); ++i){
            if('/' == path[i]){
                if(".." == ans){
                    if(!vstack.empty()) vstack.pop_back();
                }else if("" != ans && "." != ans){
                    vstack.push_back(ans);
                }
                ans = "";
            }else{
                ans += path[i];
            }
        }
        
        if(vstack.empty()) ans = "/";
        else{
            ans = "";
            for(int i = 0; i < vstack.size(); ++i){
                ans += ("/"+vstack[i]);
            }
        }
        
        return ans;
    }
};
