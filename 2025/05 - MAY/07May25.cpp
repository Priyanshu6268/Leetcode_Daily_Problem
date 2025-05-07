//  https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while(!pq.empty()){
            int t = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int delrow = r + drow[i];
                int delcol = c + dcol[i];
                if(delrow >= 0 && delrow < n && delcol >= 0 && delcol < m){
                    int mTime = moveTime[delrow][delcol];
                    int newTime = max(mTime+1, t+1);
                    if(newTime < time[delrow][delcol]){
                        time[delrow][delcol] = newTime;
                        pq.push({newTime, {delrow, delcol}});
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
};
