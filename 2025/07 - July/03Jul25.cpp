//    https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/
class Solution {
public:
    char kthCharacter(int k) 
    {
        string temp;
        string s = "ab";
        while(s.size() < k)
        {
            temp = s;
            for(auto &ch:temp)
            {
                if(ch == 'z') ch = 'a';
                else ch = ch + 1;
            }
            s += temp;
        }
        return s[k - 1];
    }
};
