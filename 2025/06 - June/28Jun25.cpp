//    https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>>ans;
        vector<int>arr;
        for(int i=0; i<nums.size(); i++){
            ans.push_back({i, nums[i]});
        }
        auto lambda=[](auto p1, auto p2){
            return p1.second>p2.second;
        };
        sort(ans.begin(), ans.end(), lambda);
        sort(ans.begin(), ans.begin()+k);
        for(int i=0; i<k; i++){
            arr.push_back(ans[i].second);
        }
        return arr;
    }
};
