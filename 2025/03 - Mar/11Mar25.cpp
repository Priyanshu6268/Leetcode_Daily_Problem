//    https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int left = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            while (freq.size() == 3) {
                cnt += s.size() - i;
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
        }
        return cnt;
    }
};
