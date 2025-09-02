//    https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int, int>> p;
        for (auto pp: points) {
            p.push_back({pp[0], -pp[1]});
        }

        sort(p.begin(), p.end());

        int ans = 0;
        for (int i = 0; i < p.size(); ++i) {
            int cur = 0, x, y;
            for (int j = i + 1; j < p.size(); ++j) {
                if (cur == 0) {
                    if (-p[j].second <= -p[i].second) {
                        cur++;
                        x = p[j].first, y = -p[j].second;
                        continue;
                    }
                } else {
                    if (p[j].first > x && -p[j].second > y && -p[j].second <= -p[i].second) {
                        cur++;
                        x = p[j].first, y = -p[j].second;
                        continue;
                    }
                }
            }
            ans += cur;
        }
        return ans;
    }
};
