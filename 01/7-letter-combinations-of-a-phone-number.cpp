/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        const string dict[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        ans.push_back("");
        for(int i = 0; i < digits.length(); ++i){
            vector<string> tmp;
            string str = dict[digits[i] - '0'];
            for(int j = 0; j < ans.size(); ++j){
                for(int k = 0; k < str.length(); ++k){
                    tmp.push_back(ans[j] + str[k]);
                }
            }
            ans = tmp;
        }
        
        return ans;
    }
};