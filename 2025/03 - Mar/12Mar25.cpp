//    https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (nums[mid] < 0)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (l < n && nums[l] != 0)
            return max(l, n - l);
        int neg = l;
        r = n - 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (nums[mid] == 0)
                l = mid + 1;
            else
                r = mid - 1; 
        }
        return max(neg, n - l);
    }
};
