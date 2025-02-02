//  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
            }
        }
        
        // Additionally, check if the last element is greater than the first element
        if (nums[n - 1] > nums[0]) {
            count++;
        }
        
        return count <= 1;
    }
};
