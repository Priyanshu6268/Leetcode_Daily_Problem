//    https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = to_string(num);
        char ch1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                ch1 = s[i];
                break;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch1) {
                s[i] = '9';
            }
        }
        int max_value = stoi(s);
        char ch2 = t[0];
        int index = 0;
        if (ch2 == '1') {
            for (int i = 0; i < t.size(); i++) {
                if (t[i] != '1' && t[i]!='0') {
                    ch2 = t[i];
                    index = i;
                    break;
                }
            }
        }
        if (ch2 != '1' && index != 0) {
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == ch2) {
                    t[i] = '0';
                }
            }
        } else {
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == ch2) {
                    t[i] = '1';
                }
            }
        }
        int min_value = stoi(t);
        return max_value - min_value;
    }
};
