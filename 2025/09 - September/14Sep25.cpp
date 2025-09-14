//    https://leetcode.com/problems/vowel-spellchecker/description/
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> cap, vow;
        
        for(string &s : wordlist){
            exact.insert(s);
            string s2 = s;
            transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
            if(!cap.count(s2)) cap[s2] = s;
            for(char &ch : s2){
                if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u') ch = '*';
            }
            if(!vow.count(s2)) vow[s2] = s;
        }
        vector<string> res(queries.size(), "");
        for(int i = 0; i < queries.size(); i++){
            if(exact.count(queries[i])) {
                res[i] = queries[i];
                continue;
            }
            string s = queries[i];
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(cap.count(s)) {
                res[i] = cap[s];
                continue;
            }
            for(char &ch : s){
                if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u') ch = '*';
            }
            if(vow.count(s)) res[i] = vow[s];
        }
        return res;
    }
};
