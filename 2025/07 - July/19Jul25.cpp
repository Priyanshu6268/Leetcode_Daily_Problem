class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(), f.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        set<string> st;
        for (auto i : f) {
            string temp = "";
            int flag = 0;
            for (auto j : i) {
                temp += j;
                if (j == '/') {
                    if (st.find(temp) != st.end()) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                continue;
            i += '/';
            st.insert(i);
        }
        vector<string> ans;
        for (auto i : st) {
            i.pop_back();
            ans.push_back(i);
        }
        return ans;
    }
};
