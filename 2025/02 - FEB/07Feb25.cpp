//      https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int distinct = 0;
        unordered_map<int, int> freq, colors;
        vector<int> res;
        for (auto& q : queries){
            int x = q[0], y = q[1];
            distinct += (++freq[y] == 1);
            if (colors[x] != 0){
                distinct -= (--freq[colors[x]] == 0);
            }
            colors[x] = y;
            res.push_back(distinct);
        }
        return res;
    }
};
