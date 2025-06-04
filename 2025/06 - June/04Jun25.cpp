//    https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size(), m = n - numFriends + 1;
        string res = "";
        for (int i = 0; i < n; ++i) {
            res = max(res, word.substr(i, m));
        }
        return res;
    }
};
