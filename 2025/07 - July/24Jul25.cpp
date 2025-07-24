//      https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/
class Solution {
public:
    int ans,sum3;
    int dp[1005],height[1005];
    void dfs1(int x, int par, vector<int>v[], vector<int>&nums,int h)
    {
        height[x]=h;
        dp[x]=nums[x];
        for(int i=0; i<v[x].size(); i++)
        {
            int child=v[x][i];
            if(child!=par)
            {
                dfs1(child,x,v,nums,h+1);
                dp[x]^=dp[child];
            }
        }
    }
    int findans(int z, int x, int y)
    {
       int mini=min({x,y,z});
       int maxi=max({x,y,z});

       return maxi-mini;
    }
    void dfs(int x, int par, vector<int>v[],int prev, int prev1)
    {
        for(int i=0; i<v[x].size(); i++)
        {
            int child=v[x][i];
            if(child!=par)
            {
                int z=dp[child];
                ans=min(ans,findans(z,prev^z,prev1));
                // cout<<findans(z,prev^z,prev1)<<endl;
                dfs(child,x,v,prev,prev1);
            }
        }
    }

    void dfs2(int x, int par, vector<int>v[],int same, int bacha, int y)
    {
        for(int i=0; i<v[x].size(); i++)
        {
            int child=v[x][i];
            if(child!=par)
            {
                if(height[child]<height[x] && y==1)
                {
                    int z=dp[x];
                    int z1=z^same;
                    ans=min(ans,findans(z^same,same,bacha^z1));
                    //cout<<x<<" "<<child<<" "<<ans<<" "<<(z^same)<<" "<<(same)<<" "<<(bacha^z1)<<endl;
                    dfs2(child,x,v,same,bacha,1);
                }
                else if((height[child]>height[x] && y==1) || y==-1)
                {
                    int z=dp[child];
                    ans=min(ans,findans(z,same,bacha^z));
                    dfs2(child,x,v,same,bacha,-1);
                }
                
            }
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=edges.size();
        ans=INT_MAX;
        sum3=0;
        for(int i=0; i<nums.size(); i++) sum3^=nums[i];
        vector<int>v[n+1];
        for(int i=0; i<n; i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(0,-1,v,nums,1);
        for(int i=0; i<n; i++)
        {
            int x=edges[i][0],y=edges[i][1];
            if(height[x]>height[y]) swap(x,y);
            dfs(y,x,v,dp[y],sum3^dp[y]);
            dfs2(x,y,v,dp[y],sum3^dp[y],1);
        }
        return ans;
    }
};
