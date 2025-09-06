//    https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/
class Solution {
public:
    long long solve(long long n) {
        long long p = 1;
        long long ans = 0;
        long long d = 1;
        while(p <= n) {
            p *= 4;
            long long have = min(n - (p/4) + 1 , p - p/4);
            ans += have*d;
            d++;
        }
        return ans;
    }

    long long calc(int l , int r) {
        return solve(r) - solve(l-1);
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto &x : queries) {
            long long mvs = calc(x[0],x[1]);
            ans += (mvs+1)/2;
        }
        return ans;
    }
};
