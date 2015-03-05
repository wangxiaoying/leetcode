/*

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

*/

class Solution {
public:
	void findCombination(vector<int> &candidates, vector<vector<int>> &ans, int target, int pos, vector<int> tmp){
		if(pos >= candidates.size()) return;
		if(pos && candidates[pos] == candidates[pos-1]){
			findCombination(candidates, ans, target, pos+1, tmp);
		}
		
		if(target < candidates[pos]) return;
		
		while(target > 0){
			findCombination(candidates, ans, target, pos+1, tmp);
			tmp.push_back(candidates[pos]);
			target -= candidates[pos];
		}
		if(0 == target) ans.push_back(tmp);

	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> ans;
		
		sort(candidates.begin(), candidates.end());
		
		if(candidates.size()){
			findCombination(candidates, ans, target, 0, *new vector<int>);
		}
		
		return ans;
	}
};