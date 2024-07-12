//    https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
class Solution {
private:
    int remove(string& s, const string& pattern, int score) {
        vector<char> st; 
        int scores = 0;
        for (char c : s) {
            if (!st.empty() && st.back() == pattern[0] && c == pattern[1]) {
                st.pop_back();
                scores += score;
            } else {
                st.push_back(c); 
            }
        }
        s = string(st.begin(), st.end()); 
        return scores;
    }

public:
    int maximumGain(string s, int x, int y) {
        int score1 = 0, score2 = 0;
        if (x >= y) {
            score1 = remove(s, "ab", x);
            score2 = remove(s, "ba", y);
        } else {
            score2 = remove(s, "ba", y);
            score1 = remove(s, "ab", x);
        }
        return score1 + score2;
    }
};
