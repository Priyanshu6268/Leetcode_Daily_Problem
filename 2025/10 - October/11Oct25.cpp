//      https://leetcode.com/problems/maximum-total-damage-with-spell-casting/
class Solution {
public:
    typedef long long ll;
    
    ll dp[100003];
    
    ll f(int i,vector<pair<ll, ll>>&temp){
        int n=temp.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        ll notTake= f(i+1, temp);
        
        ll take= temp[i].first* temp[i].second;
        int idx=i+1;
        for(;idx<n;idx++){
            if(temp[idx].first>temp[i].first+2)break;
        }
        take+=f(idx, temp);
        return dp[i]=max(take, notTake);
        
    }
    
    long long maximumTotalDamage(vector<int>& a) {
     sort(a.begin(), a.end());
        int n=a.size();
        memset(dp, -1, sizeof(dp));
        map<ll, ll>freq;
        for(int i=0;i<n;i++){
             freq[a[i]]++;
        }
        vector<pair<ll, ll>>temp;
        for(auto it: freq)temp.push_back(it);
        
        
        
        return f(0,temp);
    }
};
