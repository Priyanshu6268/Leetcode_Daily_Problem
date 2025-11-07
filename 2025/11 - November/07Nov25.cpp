//      https://leetcode.com/problems/maximize-the-minimum-powered-city/description/
class Solution {
public:
    long long have[100005];
    bool poss(vector<int>& stations, int range, int k, long long curTry){
        long long kLeft = k;
        int n = stations.size();
        vector<long long> newHave(n+1, 0);
        for(int i=0;i<n;i++) {
            newHave[i] = have[i];
        }
        vector<long long> newAdd(n+1, 0);
        for(int i = 0 ; i < n; i++){
            if(i > 0) {
                newAdd[i] += newAdd[i-1];
                newHave[i] += newAdd[i];
            }
            long long need = curTry - newHave[i];
            if(need <= 0) continue;
            kLeft -= need;
            if(kLeft < 0) return false;
            int rangeEnd = min(1ll*n-1, 2ll * range + i);
            newAdd[i] += need;
            newAdd[rangeEnd + 1] -= need;
        }
        return kLeft >= 0;
    }

    long long maxPower(vector<int>& stations, int range, int k) {
        int n = stations.size();
        memset(have, 0, sizeof(have));
        for(int i=0;i<n;i++){
            int curr = i;
            int left = max(0, curr - range);
            int right = min(n-1, curr + range);
            have[left] += stations[i];
            have[right+1] -= stations[i];
        }
        for(int i = 1; i <= n-1; i++){
            have[i] += have[i-1];
        }
        long long l = 0, r = 1e12, ans = l*1ll;
        while(l <= r){
            long long mid = (l + r)/2;
            if(poss(stations, range, k, mid)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
