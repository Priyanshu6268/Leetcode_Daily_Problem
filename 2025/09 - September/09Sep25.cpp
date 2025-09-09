//      https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/
class Solution {
public:
    const int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1);
        dp[1]=1;
        long long total=0;

        for(int day=2;day<=n;day++){
            if(day-delay>=1){
                total= (total+dp[day-delay])%MOD;
            }
            if(day-forget>=1){
                total = (total - dp[day-forget]+MOD)%MOD;
            }
            dp[day]=total;
        }
        long long ans=0;
        for(int day=n-forget+1;day<=n;day++){
            ans = (ans+dp[day])%MOD;
        }
        return ans;
    }
};
