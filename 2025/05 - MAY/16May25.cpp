//    https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<pair<int, int>> f(n, {1, -1});
        int maxIndex = 0, maxLen = 1;
        for (int i = 1; i < n; i++) {
            int bestIndex = -1, bestLen = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (f[j].first <= bestLen) continue;
                if (words[i].size() != words[j].size()) continue;
                if (groups[i] == groups[j]) continue;
                int dif = 0;
                for (int k = 0; k < words[i].size(); k++) dif += words[i][k] != words[j][k];
                if (dif != 1) continue;
                bestIndex = j;
                bestLen = f[j].first;
            }
            f[i] = {bestLen + 1, bestIndex};
            if (bestLen + 1 > maxLen) {
                maxIndex = i;
                maxLen = bestLen + 1;
            }
        }
        vector<string> ans;
        while (maxIndex != -1) {
            ans.push_back(words[maxIndex]);
            maxIndex = f[maxIndex].second;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
