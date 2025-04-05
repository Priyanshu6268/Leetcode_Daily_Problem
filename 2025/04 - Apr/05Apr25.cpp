//    https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
class Solution {
public:
    long long ans;
    void rec(int idx , int &n , vector<int>& v, int cur){
        if(idx>=n){
            ans+=cur;
            return;
        }
        rec(idx+1 , n , v , cur^v[idx]); 
        rec(idx+1 , n , v , cur);
    }
    int subsetXORSum(vector<int>& v) {
        int n=v.size(); 
        rec(0 , n , v , 0);
        return ans;
    }
};
