//    https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/
class Solution {
public:
    int maxFreeTime(int end, int k, vector<int>& s, vector<int>& e) {
        vector<int>v;
        v.push_back(s[0]);
        for(int i=1;i<s.size();i++)
            {
                v.push_back(abs(e[i-1]-s[i]));
            }
        v.push_back(abs(e[e.size()-1]-end));
        int x=v[0],m=0,n=0;
        for(int i=1;i<=k;i++)
            {
                x+=v[i];
            }m=x;
        for(int i=k+1;i<v.size();i++)
        {
            x-=v[n];
            x+=v[i];
            m=max(m,x);
            n++;
        }
            return m;
    }
};
