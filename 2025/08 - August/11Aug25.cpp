//    https://leetcode.com/problems/range-product-queries-of-powers/description/
#define Mod 1000000007
class Solution {
public:
    vector<int> productQueries(int N, vector<vector<int>>& q) {
        int size = q.size();
        vector<int> ans,pre;
        for(int i=0;i<31;i++){
            if((N>>i)&1){
                ans.push_back(pow(2,i));
            }
        }

        for(int i=0;i<size;i++)
        {
            long long x=1;
            for(int j=q[i][0];j<=q[i][1];j++){
                x=(x*ans[j])%Mod;
            }  
            pre.push_back(x);
        }
        return pre;
    }
};
