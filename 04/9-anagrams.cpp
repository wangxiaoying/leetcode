/*

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*/


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        map<string, vector<int>> map_strs;
        
        for(int i = 0; i < strs.size(); ++i){
            string stemp = strs[i];
            sort(stemp.begin(), stemp.end());
            map_strs[stemp].push_back(i);
        }
        
        for(map<string, vector<int>>::iterator itr = map_strs.begin(); itr != map_strs.end(); ++itr){
            if(itr->second.size() > 1){
                for(vector<int>::iterator vitr = itr->second.begin(); vitr != itr->second.end(); ++vitr){
                    ans.push_back(strs[*vitr]);
                }
            }
        }
        
        return ans;
    }
};