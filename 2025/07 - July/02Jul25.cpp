//    https://leetcode.com/problems/find-the-original-typed-string-ii/description/
class Solution {
public:
    
    int possibleStringCount(string word, int k) {
        int n = word.size();
        int i = 0;
        vector<int>v;
        while(i<n){
            int cnt = 0;
            char c= word[i];
            while(i<n && c==word[i]){
                cnt++;
                i++;
            }
            v.push_back(cnt);
        }
        int sz = min((int)v.size(),k);
        long long mod = 1e9+7;
        long long dp[sz+1][k+1],pref[sz+1][k+1];
        long long mul = 1;
        for(int i = v.size()-1;i>=sz;i--) mul = (mul*v[i])%mod;
        memset(dp,0,sizeof dp);
        memset(pref,0,sizeof dp);
        dp[sz][k] = pref[sz][k] = 1;
        for(int i = sz-1;i>=0;i--){
            for(int j=k;j>=0;j--){
             
                dp[i][j]+=pref[i+1][min(k,v[i]+j)]-pref[i+1][j];
                dp[i][j]%=mod;
                if(k-j<v[i]) dp[i][j]+=((v[i]-k+j)*dp[i+1][k])%mod;
                dp[i][j]%=mod;
            }
            pref[i][0] = dp[i][0];
            for(int j = 1;j<=k;j++) pref[i][j]=dp[i][j]+pref[i][j-1];
        }
        long long ans = dp[0][0];
        ans = (ans*mul)%mod;
        return ans;

    }
};
