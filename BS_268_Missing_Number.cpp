//268. Missing Number
https://leetcode.com/problems/missing-number/description/
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int ans = (n*(n+1))/2;

//         for(int num : nums){
//             ans -= num;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while(left<=right){
            int mid = left + ((right - left)/2);

            if(nums[mid] > mid){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 

        return left;
    }
};
