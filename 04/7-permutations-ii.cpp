/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/


class Solution {
public:
	void compute(map<int, int> &num_count, vector<vector<int>> &ans, vector<int> &temp, int num_size){
		if(num_size == temp.size()){
			ans.push_back(temp);
			return;
		}
		
		for(map<int, int>::iterator itr = num_count.begin(); itr != num_count.end(); ++itr){
			int number = itr->first;
			int count = itr->second;
			if(!temp.empty() && temp.back() == number) continue;
			while(num_count[number]){
				temp.push_back(number);
				num_count[number]--;
				compute(num_count, ans, temp, num_size);
			}
			for(int i = 0; i < count; ++i) temp.pop_back();
				num_count[number] = count;
		}
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> ans;
		map<int, int> num_count;
		for(vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr){
			num_count[*itr]++;
		}
		
		compute(num_count, ans, *new vector<int>(), (int)num.size());
		return ans;
	}
};