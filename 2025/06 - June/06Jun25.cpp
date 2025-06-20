//    https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/
class Solution {
public:
    string robotWithString(string s) {
        string ans, t, mn = s;
        for(int i=s.size()-2; i>=0; i--) mn[i] = min(s[i], mn[i + 1]);
        
        for(int i=0; i<s.size(); i++) {
            while(t.size() && t.back() <= mn[i]) ans += t.back(), t.pop_back();
            t += s[i];
        }
        reverse(t.begin(), t.end());
        return ans + t;
    }
};
