/*

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.

*/


class Solution {
private:
    vector<string> spaces;
public:
    string createString(vector<string> &vtemp, int remain){
        string s = "";
        
        if(vtemp.empty()) s = spaces[remain];
        else if(vtemp.size() == 1){
            s = vtemp[0]+spaces[remain];
        }else{
            int size = (int)vtemp.size();
            int slen = remain/(size-1), sleft = remain%(size-1);
            s = vtemp[0];
            for(int i = 1; i < size; ++i){
                if(sleft > 0) s += spaces[slen+1];
                else s += spaces[slen];
                sleft--;
                s+= vtemp[i];
            }
        }
        
        return s;
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        if(0 == words.size()) return ans;
        
        string s = "";
        for(int i = 0; i <= L; ++i){
            spaces.push_back(s);
            s += ' ';
        }
        
        int remain = L, len = 0, count = 0;
        vector<string> vtemp;
        for(int i = 0; i < words.size(); ++i){
            len = (int)words[i].length();
            if(0 == len) continue;
            if(remain - count < len){
                ans.push_back(createString(vtemp, remain));
                remain = L;
                i--;
                count = 0;
                vtemp.clear();
            }else{
                vtemp.push_back(words[i]);
                remain -= len;
                count++;
            }
        }
        
        if(vtemp.empty()){
            ans.push_back(spaces[L]);
        }else{
            s = vtemp[0];
            for(int i = 1; i < vtemp.size(); ++i){
                s += " ";
                s += vtemp[i];
            }
            s += spaces[remain-count+1];
            ans.push_back(s);
        }
        
        return ans;
    }
    
};