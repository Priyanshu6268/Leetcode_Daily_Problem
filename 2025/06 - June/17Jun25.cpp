//    https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/
class Solution {
    const int MOD = 1e9 + 7;
    int fastExpMod(int x, int n) {
        if(n == 0) return 1;
        long y = fastExpMod(x, n / 2);
        if(n % 2) return ((y * y) % MOD * x) % MOD; 
        return (y * y) % MOD;
    }
    int nCr(int n, int r) {
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for(int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * 1LL * i) % MOD;
        }
        r = max(r, n - r);
        vector<int> invFactorial(r + 1);
        invFactorial[r] = fastExpMod(factorial[r], MOD - 2);
        for(int i = r; i; i--) {
            invFactorial[i - 1] = (invFactorial[i] * 1LL * i) % MOD;
        }
        return (((factorial[n] * 1LL * invFactorial[r]) % MOD) * 1LL * invFactorial[n - r]) % MOD;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        int ans = (((m * 1LL * fastExpMod(m - 1, n - k - 1)) % MOD) * nCr(n - 1, k)) % MOD;
        return ans;
    }
};
