//.   https://leetcode.com/problems/maximize-happiness-of-selected-children/
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int offset = 0;
        long long ans = 0, val;
        priority_queue<int> pq;
        for(int h: happiness)
            pq.push(h);
        for(int i = 0;i<k;i++){
            val = max(0LL, 1LL * pq.top() - offset);
            if(val == 0)
                break;
            ans += val;
            offset++;
            pq.pop();
        }
        return ans;
    }
};
