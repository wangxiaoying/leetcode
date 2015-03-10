/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

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
class Solution {
public:
    static bool compare(Interval a, Interval b){
        if(a.start == b.start) return a.end < b.end;
        else return a.start < b.start;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;

        if(intervals.empty()){
            ans.push_back(newInterval);
            return ans;
        }
        
        int left = 0, right = (int)intervals.size()-1;
        
        while(left < intervals.size() && intervals[left].end < newInterval.start) left++;
        while(right >= 0 && intervals[right].start > newInterval.end) right--;
        
        if(intervals.size() == left || -1 == right || left > right){
            ans = intervals;
            ans.push_back(newInterval);
            sort(ans.begin(), ans.end(), compare);
            return ans;
        }
        
        for(int i = 0; i < left; ++i) ans.push_back(intervals[i]);
        
        ans.push_back(*new Interval(min(newInterval.start, intervals[left].start), max(newInterval.end, intervals[right].end)));
        
        for(int i = right+1; i < intervals.size(); ++i) ans.push_back(intervals[i]);
        
        return ans;
    }
};