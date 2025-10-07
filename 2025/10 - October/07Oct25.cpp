//    https://leetcode.com/problems/avoid-flood-in-the-city/description/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> filled;
        set<int> dryday;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0)
                dryday.insert(i);
            else {
                 ans[i] = -1;
                 if (filled.find(rains[i]) != filled.end()) {
                    int lst_filled = filled[rains[i]];
                    auto it = dryday.upper_bound(lst_filled);

                    if (it == dryday.end())
                        return {};

                    ans[*it] = rains[i];
                    dryday.erase(it);
                }
                 filled[rains[i]]=i;
            }
        }
        return ans;
    }
};
