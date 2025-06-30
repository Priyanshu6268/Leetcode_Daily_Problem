//    https://leetcode.com/problems/longest-harmonious-subsequence/description/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& i : nums){
            freq[i]++;
        }

        int maxLen = 0;
        for(auto [num, count] : freq){
            if(freq.count(num + 1)){
                maxLen = max(maxLen, count + freq[num + 1]);
            }
        }

        return maxLen;
    }
};
