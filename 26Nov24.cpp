//    https://leetcode.com/problems/find-champion-ii/description/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n==1) return 0;
        bitset<128> deg0;
        deg0.set();
        for(auto& e: edges) deg0[e[1]]=0;
        uint64_t* d=(uint64_t*)&deg0;
        if (n<=64){
            d[1]=0;
            if (n<64) d[0]&=(1ull<<n)-1;
        }
        else d[1]&=(1ull<<(n-64))-1;
        if (popcount(d[0])+popcount(d[1])!=1)
            return -1;
        else{
            int d0=countr_zero(d[0]);
            return d0==64?64+countr_zero(d[1]):d0;
        }
    }
};
