//    https://leetcode.com/problems/delete-columns-to-make-sorted/description/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool sorted=is_sorted(strs.begin(),strs.end(),[i](const string &a, const string &b){return a[i]<b[i];});
            if(!sorted) cnt++;
        }
        return cnt;
    }
};
