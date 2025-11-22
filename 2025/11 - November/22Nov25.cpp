//.    https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [&](int x){
            return x%3!=0; });
    }
};
