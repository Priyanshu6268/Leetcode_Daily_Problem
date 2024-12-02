//      https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        string s;
        int ans = 0;
        stringstream ss(sentence);
        while(ss >> s)
        {
            ans++;
            if(s.find(searchWord) == 0) return ans;
        }
        return -1;
    }
};
