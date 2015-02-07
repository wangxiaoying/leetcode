/*

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        const int count_words = L.size();
        const int length_string = S.length();
        
        if(count_words <= 0 || length_string <= 0) return ans;
        
        const int length_word = L[0].length();
        map<string, int> dict;
        for(int i = 0; i < count_words; ++i){
            dict[L[i]]++;
        }
        
        
        for(int i = 0; i < length_word; ++i){
            map<string, int> tmp;
            int left_pos = i, count = 0;
            
            for(int j = i; j <= length_string - length_word; j += length_word){
                string str = S.substr(j, length_word);
                if(dict.count(str)){
                    tmp[str]++;
                    if(tmp[str] <= dict[str]) count++;
                    else{
                        while(tmp[str] > dict[str]){
                            string tstr = S.substr(left_pos, length_word);
                            tmp[tstr]--;
                            left_pos += length_word;
                            count--;
                        }
                        count++;
                    }
                    
                    if(count == count_words){
                        ans.push_back(left_pos);
                        tmp[S.substr(left_pos, length_word)]--;
                        count--;
                        left_pos += length_word;
                    }
                    
                }else{
                    tmp.clear();
                    count = 0;
                    left_pos = j + length_word;
                }
            }
        }
        
        return ans;
    }
};