/*

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

*/


class Solution {
private:
    vector<int> factorial;
public:
    void computeFac(){
        factorial.push_back(1);
        factorial.push_back(1);
        for(int i = 2; i < 10; ++i){
            factorial.push_back(factorial.back()*i);
        }
    }
    
    void getNumber(int n, int k, vector<bool> &flags, string &ans, int index){
        if(0 == index) return;
        
        for(int i = 1; i <= n; ++i){
            if(flags[i]) continue;
            if(k <= factorial[index-1]){
                ans += '0'+i;
                flags[i] = true;
                getNumber(n, k, flags, ans, index-1);
            }else{
                k -= factorial[index-1];
            }
        }
        
    }
    
    string getPermutation(int n, int k) {
        computeFac();
        string ans = "";
        if(k <= 0 || k > factorial[n]) return ans;
        
        vector<bool> flags(n+1, false);
        getNumber(n, k, flags, ans, n);
        
        return ans;
    }
};
