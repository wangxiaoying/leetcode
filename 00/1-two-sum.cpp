/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

#include <utility>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int min3(int a, int b, int c){
		return min(min(a, b), c);
	}

	int max3(int a, int b, int c){
		return max(max(a, b), c);
	}

	int midIndex(vector<int> &numbers, int l, int r, int m){
		int mini = min3(numbers[l], numbers[r], numbers[m]);
		int maxi = max3(numbers[l], numbers[r], numbers[m]);
		if(numbers[l] > mini && numbers[l] < maxi) return l;
		else if(numbers[r] > mini && numbers[r] < maxi) return r;
		else return m;
	}

	void quickSort(vector<int> &numbers, int l, int r){
		if(r - l <= 1) return;

		int p = midIndex(numbers, l, r-1, (r+l-1)/2);
		swap(numbers[l], numbers[p]);

		int pivot = numbers[l];
		int i = l + 1;
		for(int j = i; j < r; ++j){
			if(numbers[j] < pivot){
				swap(numbers[i], numbers[j]);
				i++;
			}
		}

		swap(numbers[l], numbers[i-1]);

		quickSort(numbers, l, i-1);
		quickSort(numbers, i, r);
	}

	int lookUp(vector<int> &numbers, int target, int before){
		for(int i = 0; i < numbers.size(); ++i){
			if(target == numbers[i] && i+1 != before) return i+1;
		}

		return 0;
	}

	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> copy(numbers);

		quickSort(numbers, 0, numbers.size());

		int small = 0, big = numbers.size()-1;

		while(true && small < big){
			int tmp = numbers[small] + numbers[big];
			if(target == tmp) break;
			else if(target > tmp) small++;
			else big--;
		}

		vector<int> ans;
		if(small >= big){
			ans.push_back(0);
			ans.push_back(0);
			return ans;
		}

		int index1 = lookUp(copy, numbers[small], 0);
		int index2 = lookUp(copy, numbers[big], index1);
		if(index2 < index1) swap(index1, index2);

		ans.push_back(index1);
		ans.push_back(index2);

		return ans;
	}
};




