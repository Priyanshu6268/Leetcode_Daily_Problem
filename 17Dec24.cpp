//      https://leetcode.com/problems/construct-string-with-repeat-limit/description/

class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int n = s.length();
        bool rem = false;
        int backInd = 0;
        vector<int>v(26,0);
        for(auto ele : s)
        {
            v[ele - 'a']++;
        }
        string res = "";
        int c = 0;
        for(int i = 25; i >= 0; i--)
        {
            while(v[i] > 0)
            {
                if(c < limit)
                {
                    res += i + 'a';
                    c++;
                    v[i]--;
                }
                else 
                {
                    if(v[i] > 0)
                    {
                        backInd = i;
                        rem = true;
                        break;
                    }
                }
                if(rem)
                {
                    c = 0;
                    i = backInd;
                    rem = false;
                    
                }
                
                    
            }
            c = 0;
        }
        return res;
    }
};
