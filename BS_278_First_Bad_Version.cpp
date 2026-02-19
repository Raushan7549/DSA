// https://leetcode.com/problems/first-bad-version/description/
// 278. First Bad Version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0;
        int r = n;
        int ans = -1;

        while ( l <= r){
            int m = l + ((r-l) >> 1);
            bool version = isBadVersion(m);

            if(version){
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
