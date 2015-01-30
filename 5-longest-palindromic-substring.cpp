/*

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/
class Solution {
public:
    string init(string s){
        string new_string = "$#";
        for(int i=0; i < s.length(); ++i){
            new_string += s[i];
            new_string += "#";
        }
        return new_string;
    }
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        string new_string = init(s);
        string ans;
        int mx = 0;
        int id;
        vector<int> p;
        p.push_back(1);
        
        for(int i = 1; i < new_string.length(); ++i){
            if(mx > i){
                p.push_back(min(mx-i, p[2*id-i]));
            }else{
                p.push_back(1);
            }
            for(; new_string[i+p[i]] == new_string[i-p[i]]; p[i]++);
            if(i+p[i] > mx){
                mx = i + p[i];
                id = i;
            }
        }
        
        int max = p[0];
        int index = 0;
        for(int i = 1; i < new_string.length(); ++i){
            if(max < p[i]){
              max = p[i];
              index = i;
            } 
        }
        
        ans.assign(s, index/2-max/2, max-1);
        return ans;
    }
};