//      https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
class Solution {
public:
    vector<vector<int>> dp;
    int yesMaxValue(vector<vector<int>>& events, int i, int k, int prevEnd)
    {
        if (i >= events.size())
            return 0;
        
        if (k == 0)
            return 0;
        
        if (events[i][0] <= prevEnd)
            return yesMaxValue(events, i + 1, k, prevEnd);
        
        if (dp[i][k] != -1)
            return dp[i][k];
        
        int pick = events[i][2] + yesMaxValue(events, i + 1, k - 1, events[i][1]);
        int notPick = yesMaxValue(events, i + 1, k, prevEnd);

        return dp[i][k] = max(pick, notPick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();

        dp.resize(n, vector<int> (k + 1, -1));
        return yesMaxValue(events, 0, k, 0);
    }
};
