//  https://leetcode.com/problems/circular-sentence/description/
class Solution {
private:
    vector<string> split(string &s, const char &c) {
        int n = s.size(), l = 0, r = 0;
        s.push_back(c);
        vector<string> res;
        do {
            while (s[r] != c) r++;
            string word = s.substr(l, r - l);
            if (!word.empty()) {
                res.push_back(word);
            }
            while (s[r] == c) r++;
            l = r;
        } while (r < n);
        return res;
    }
public:
    bool isCircularSentence(string &s) {
        if (s[0] != s.back()) return false;
        vector<string> arr = split(s, ' ');
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i].back() != arr[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};
