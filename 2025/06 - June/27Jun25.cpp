//    https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/
class Solution {
public:
    bool check(string s, string temp, int k) {
        string a = "";
        for (int i = 0; i < k; i++) {
            a += temp;
        }
        int n = a.size();
        int m = s.size();
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (a[i] == s[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return (i == n);
    }

    void permute(string& a, string& u, int k, string s) {
        sort(a.begin(), a.end());  
        do {
            if (check(s, a, k) && u.compare(a) < 0) {
                u = a;
            }
        } while (next_permutation(a.begin(), a.end()));
    }

    void fun2(string take, int id, int sz, string s, string ans, string &fans, int k, int tsize) {
        if (sz == 0) {
            permute(ans, fans, k, s);
            return;
        }
        if (id == tsize) {
            return;
        }
        fun2(take, id + 1, sz, s, ans, fans, k, tsize);
        ans += take[id];
        fun2(take, id + 1, sz - 1, s, ans, fans, k, tsize);
        ans.pop_back();
    }

    string fun(string take, int size, string s, int k) {
        if (take.size() < size) {
            return "";
        }
        string fans = "";
        string ans = "";
        fun2(take, 0, size, s, ans, fans, k, take.size());

        return fans;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        map<int, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a']++;
        }
        string take = "";

        for (auto it : mp) {
            int h = it.second / k;
            while (h > 0) {
                take += it.first + 'a';
                h--;
            }
        }
        if (take.size() <= 1) {
            return take;
        }

        int low = 0;
        int high = 8; 
        string ans = "";
        while (low <= high) {
            int mid = (low + high) / 2;

            string h = fun(take, mid, s, k);

            if (h == "") {
                high = mid - 1;
            } else {
                ans = h;
                low = mid + 1;
            }
        }

        return ans;
    }
};
