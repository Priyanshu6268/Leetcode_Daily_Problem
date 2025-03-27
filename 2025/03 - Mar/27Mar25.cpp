//    https://leetcode.com/problems/minimum-index-of-a-valid-split/description/
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>firstMap,secondMap;
        int n = nums.size();
        for(int num : nums){
            secondMap[num]++;
        }
        for(int i = 0 ; i < n - 1 ; i++){
            int num = nums[i];
            firstMap[num]++;
            secondMap[num]--;
            if(firstMap[num] * 2 > i + 1 && secondMap[num] * 2 > n - i -1){
                return i;
            }
        }
        return -1;
    }
};
