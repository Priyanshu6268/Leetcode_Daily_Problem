//    https://leetcode.com/problems/sort-an-array/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums.begin(),nums.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};
