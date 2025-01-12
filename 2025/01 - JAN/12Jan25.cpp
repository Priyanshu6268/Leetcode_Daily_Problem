//      https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2!=0)return false;
        int t=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'|| s[i]=='(') t++;
            else t--;
            if(t<0)return false;
        }
        t=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'|| s[i]==')') t++;
            else t--;
            if(t<0)return false;
        }
        return true;
    }
};
