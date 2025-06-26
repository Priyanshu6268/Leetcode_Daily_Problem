//  https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')count++;
        }
        long long c=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                if(k>=c)k-=c,count++;
                else break;
            }
            if(c>=k)break;
            c*=2;
        }
        return count;
    }
};
