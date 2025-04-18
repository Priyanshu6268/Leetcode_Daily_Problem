//    https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<string>subbstr;
        vector<int>a(26, 0); 
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(a[s[i] - 'a'] == 0){
                string sub = s.substr(i, n - i);
                subbstr.push_back(sub);
                a[s[i] - 'a'] = 1;
            }
        }
        int res = 0;
        for(int i = 0; i < subbstr.size(); i++){
            a.clear();
            a.resize(26, 0);
            int j = subbstr[i].size() - 1;
            while(j > 0 && subbstr[i][j] != subbstr[i][0]){
                j--;
            }
            j -= 1;
            while(j > 0 ){
                if(a[subbstr[i][j] - 'a'] == 0){
                    res++;
                    a[subbstr[i][j] - 'a'] = 1;
                }
                j--;
            }
        }
        return res;
    }
};
