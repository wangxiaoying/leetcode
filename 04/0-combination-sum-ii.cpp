/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/

class Solution {
public:
	void findCombination(vector<int> &candidates, map<int, int> &map_candidates, vector<vector<int>> &ans, int target, int pos, vector<int> tmp){
		
		if(pos >= candidates.size()) return;
		if(pos && candidates[pos] == candidates[pos-1]){
			findCombination(candidates, map_candidates, ans, target, pos+1, tmp);
		}
		
		if(target < candidates[pos]) return;
		
		int count = 0;
		while(target > 0 && count <= map_candidates[candidates[pos]]){
			findCombination(candidates, map_candidates, ans, target, pos+1, tmp);
			if(count == map_candidates[candidates[pos]]) break;
			tmp.push_back(candidates[pos]);
			target -= candidates[pos];
			count++;
		}
		if(0 == target) ans.push_back(tmp);

		
	}

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> ans;
		vector<int> candidates;
		map<int, int> map_candidates;
		for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr){
			map_candidates[*itr]++;
		}
		
		
		for(map<int, int>::iterator iter = map_candidates.begin(); iter != map_candidates.end(); ++iter){
			candidates.push_back(iter->first);
		}
		
		for(int i = 0; i < num.size(); ++i){
			cout<<num[i]<<" ";
		}
		cout<<endl;
		
		if(num.size()){
			findCombination(candidates, map_candidates, ans, target, 0, *new vector<int>);
		}
		
		return ans;
		
	}
};