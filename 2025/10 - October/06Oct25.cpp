//    https://leetcode.com/problems/swim-in-rising-water/description/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>> , greater<>> pq;
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({grid[0][0],0,0});
        int ans = grid[0][0];
        while(!pq.empty()){
            auto [val,i,j] = pq.top();
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j]=true;

            ans=max(ans,val);
            if(i==n-1 && j==n-1) return ans;

            for(int k = 0 ; k<4 ; k++){
                int x =i+dir[k][0] , y = j+dir[k][1];
                if(x<0 || y<0 || x>=n || y>=n || vis[x][y]) continue;
                pq.push({grid[x][y],x,y});
            }
        }
        return ans;
    }
};
