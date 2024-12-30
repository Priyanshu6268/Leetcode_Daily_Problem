//      https://leetcode.com/problems/count-ways-to-build-good-strings/description/
class Solution {
public:
    long long mod=1e9+7;
    int solve(int low, int high,int zero,int one,int s,vector<int> &dp){
        if(s>high){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s];
        }
        //zero
        int Z;
        int O;
        if(s>=low){
            Z=1+solve(low,high,zero,one,s+zero,dp)%mod;
            O=solve(low,high,zero,one,s+one,dp)%mod;
        }
        else{
            Z=solve(low,high,zero,one,s+zero,dp)%mod;
            O=solve(low,high,zero,one,s+one,dp)%mod;
        }
        return dp[s]=Z+O;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(low,high,zero,one,0,dp)%mod;
    }
};
