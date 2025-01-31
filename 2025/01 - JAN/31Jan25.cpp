//    https://leetcode.com/problems/making-a-large-island/description/
class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
    int dfs(int i,int j,int pi,int pj,vector<vector<int>>& grid,vector<vector<pair<int,int>>>& parent){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or !grid[i][j] or (parent[i][j].first!=-1 and parent[i][j].second!=-1)){
            return 0;
        }
        int sum=1;
        parent[i][j]={pi,pj};
        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            sum+=dfs(ni,nj,pi,pj,grid,parent);
            
        }
        return sum;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxi=0;
        map<pair<int,int>,int>m;
        vector<vector<pair<int,int>>>parent(r,vector<pair<int,int>>(c,{-1,-1}));
        
        // Step-1 : Apply DFS and populate parent vector
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] and parent[i][j].first==-1 and parent[i][j].second==-1){
                    int sz=dfs(i,j,i,j,grid,parent);
                    m[{i,j}]=sz;
                    maxi=max(maxi,sz);
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!grid[i][j]){
                    int har=0;
                    set<pair<int,int>>st;
                    for(int k=0;k<4;k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if(ni>=0 and nj>=0 and ni<r and nj<c){
                            if(!st.count({parent[ni][nj].first,parent[ni][nj].second})){
                                st.insert({parent[ni][nj].first,parent[ni][nj].second});
                                har+=m[{parent[ni][nj].first,parent[ni][nj].second}];
                            }
                        }
                    }
                    maxi=max(maxi,1+har);
                }
            }
        }

        return maxi;
    }
};
