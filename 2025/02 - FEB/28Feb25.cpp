//      https://leetcode.com/problems/shortest-common-supersequence/description/
class Solution {
public:
    vector<vector<int>> lcs(string str1, string str2){
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    v[i][j] = 1+ v[i-1][j-1];
                }
                else{
                int case1 = v[i-1][j];
                int case2 = v[i][j-1];
                v[i][j] = max(case1,case2);
                }
            }
        }
        return v;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>v = lcs(str1,str2);
        int n = v.size();
        int m = v[0].size();
        int i = n-1;
        int j = m-1;
        string str = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                str = str1[i-1] + str;
                i--;
                j--;
            }
            else if(v[i-1][j]>v[i][j-1]){
                str = str1[i-1] + str;
                i--;
            }
            else{
                str = str2[j-1] + str;
                j--;
            }
        }
        while(i>0){
            str = str1[i-1] + str;
            i--; 
        }
        while(j>0){
            str = str2[j-1] + str;
            j--; 
        }
        return str;
    }
};
