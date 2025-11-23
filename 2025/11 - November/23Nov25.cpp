//.     https://leetcode.com/problems/greatest-sum-divisible-by-three/
class Solution {
public:
    int dp[100005][4];
    int f(vector<int>&nums,int i,int r){
        if(i==nums.size()){
            if(r==0) return 0;
            return -1e9;
        }
        if(dp[i][r]!=-1) return dp[i][r];
        int ans = -1e9;
        ans = max(ans,f(nums,i+1,r));
        ans = max(ans,nums[i]+f(nums,i+1,(r+nums[i])%3));
        return dp[i][r] = ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0,0);
    }
};
