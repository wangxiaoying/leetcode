/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(0 >= nRows) return "";
        if(2 >= s.length() || nRows == 1 || nRows >= s.length()) return s;

        int period = 2 * (nRows - 1);
        vector<string> subStrings;
        for(int i = 0; i < nRows; ++i){
            subStrings.push_back("");
        }

        for(int i = 0; i < s.length(); ++i){
            subStrings[nRows-1 - abs(i%period - nRows+1)] += s[i];
        }

        string ans = "";
        for(int i = 0; i < nRows; ++i){
            ans += subStrings[i];
        }

        return ans;
    }
};