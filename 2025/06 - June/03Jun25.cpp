//      https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n  =status.size();
        stack<int> st;
        int ans =0;
        vector<int> opened(n,0);vector<int> got(n,0);
        for (auto it:initialBoxes) st.push(it);
        while (!st.empty()){
            auto u =st.top();st.pop();
            got[u] =1;
            if (opened[u]) continue;
            if (status[u]){
                opened[u]=1;
                ans += candies[u];
                for (auto v:keys[u]){
                    status[v]=1;
                    if (!opened[v] and got[v]) st.push(v);
                }
                for (auto v:containedBoxes[u]){
                    got[v]=1;
                    if (status[v]){
                        st.push(v);
                    }
                }
            }
        }
        return ans;

    }
};
