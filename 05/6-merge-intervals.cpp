/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool compare(Interval &a, Interval &b){
 	if(a.start == b.start) return a.end < b.end;
 	else return a.start < b.start;
 }
 
 class Solution {
 public:
 	vector<Interval> merge(vector<Interval> &intervals) {
 		vector<Interval> ans;

 		if(intervals.empty()) return ans;

 		sort(intervals.begin(), intervals.end(), compare);
 		int head = intervals[0].start, tail = intervals[0].end;
 		for(vector<Interval>::iterator itr = intervals.begin()+1; itr != intervals.end(); ++itr){
 			if(itr->start <= tail){
 				tail = max(itr->end, tail);
 			}else{
 				ans.push_back(Interval(head, tail));
 				head = itr->start;
 				tail = itr->end;
 			}
 		}
 		ans.push_back(Interval(head, tail));

 		return ans;
 	}
 };