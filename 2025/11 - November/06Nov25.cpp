//    https://leetcode.com/problems/power-grid-maintenance/description/
class Solution {
public:
    void dfs(vector<vector<int>> &g, int node, int grp, vector<int> &grps){
        grps[node] = grp;
        for (int v: g[node]){
            if (!grps[v]){
                dfs(g, v, grp, grps);
            }
        }
    }
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> g(c+1);
        int m = connections.size();
        for (int i = 0; i < m; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> grps(c+1, 0);
        int grp = 1;
        for (int i = 1; i < c + 1; i++){
            if (!grps[i]){
                dfs(g, i, grp, grps);
                grp++;
            }
        }

        vector<multiset<int>> sortGrps(c+1);
        for (int i = 1; i < c+1; i++){
            sortGrps[grps[i]].insert(i);
        }
        
        vector<int> online(c+1, 1);
        vector<int> r;
        for (int i =0; i < queries.size(); i++){
            int c = queries[i][0];
            int x = queries[i][1];

            if (c == 1){
                if (online[x]){
                    r.push_back(x);
                }else{
                    auto &order = sortGrps[grps[x]];
                        while (!order.empty() && !online[*order.begin()]){
                            order.erase(order.begin());
                        }
                        if (!order.empty()) r.push_back(*order.begin());
                        else r.push_back(-1);
                }
            }else{
                online[x] = false;
            }
        }

        return r;
    }
};
