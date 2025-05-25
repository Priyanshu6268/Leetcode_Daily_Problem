class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> hash1;
        unordered_map<string, int> hash2;
        for (auto it : words) {
            if (it[0] == it[1]) {
                hash2[it]++;
            } else {
                string rev = it;
                reverse(rev.begin(), rev.end());
                if (hash1[rev] > 0) {
                    hash1[rev]--;
                    hash1[""]++; 
                } else {
                    hash1[it]++;
                }
            }
        }

        int ans = 0;
        for (auto it : hash1) {
            if (it.first != "") continue; 
            ans += it.second * 4;
        }

        bool hasCentral = false;
        for (auto it : hash2) {
            if (it.second % 2 == 0) {
                ans += it.second * 2;
            } else {
                ans += (it.second - 1) * 2;
                hasCentral = true;
            }
        }

        if (hasCentral) ans += 2;

        return ans;
    }
};
