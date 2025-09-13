//    https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/
class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for(auto c: s) freq[c]++;
        int vowel = 0, cons = 0;
        for(auto ch: freq){
            if(isVowel(ch.first)) vowel = max(vowel, ch.second);
            else cons = max(cons, ch.second);
        }
        return vowel + cons;
    }
};
