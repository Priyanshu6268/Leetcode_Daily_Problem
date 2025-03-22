//      https://leetcode.com/problems/count-the-number-of-complete-components/description/
class Solution {
public:
    bool isComplete(int n, vector<vector<int>> &edges, vector<bool>& vis, int ele){
        queue<int> q;
        vis[ele] = true;
        q.push(ele);
        vector<int> nodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodes.push_back(node);
            for(int i: edges[node]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        int v = nodes.size();
        for(int i: nodes)
            if(static_cast<int>(edges[i].size()) != v-1)
                return false;
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i])
                if(isComplete(n, adj, vis, i))
                    res++;
        }
        return res;
    }
};
