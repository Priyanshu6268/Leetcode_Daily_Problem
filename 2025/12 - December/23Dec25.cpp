//    https://leetcode.com/problems/two-best-non-overlapping-events/
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    int lb(int target, vector<vector<int>> &events){
        int low = 0, high = events.size()-1, mid;
        while(low <= high){
            mid = (low + high)/2;
            if(events[mid][0] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comp);
        int n = events.size();
        vector<int> maxsuff(n);
        maxsuff[n-1] = events[n-1][2];
        for(int i = n-2;i>=0;i--){
            maxsuff[i] = max(maxsuff[i+1], events[i][2]);
        }
        int res = maxsuff[0], j;
        for(int i = 0;i<n;i++){
            j = lb(events[i][1]+1, events);
            if(j < n)
                res = max(res, events[i][2] + maxsuff[j]);
        }
        return res;
    }
};
