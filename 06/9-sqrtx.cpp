/*

Implement int sqrt(int x).

Compute and return the square root of x.

*/


class Solution {
public:
    long long binarySearch(long long begin, long long end, int x){
        if(begin == end) return begin;
        if(end - begin == 1){
            if(x == end*end) return end;
            else return begin;
        }

        long long mid = (begin+ end)/2;
        long long mm = mid*mid;
        if(mm < x) return binarySearch(mid, end, x);
        return binarySearch(begin, mid, x);
    }
    int sqrt(int x) {
        if(x <= 0) return 0;
        return (int)binarySearch(1, x, x);
    }
    
};
