//      https://leetcode.com/problems/valid-word/description/
class Solution {
public:
    bool isValid(string word) {
        bool vow=false;
        bool cons=false;
        int len=word.length();
        if(len<3) return false;

        for(char c:word){
            if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                c=tolower(c);
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    vow=true;
                }
                else{
                    cons=true;
                }
            }
            else if(c>='0' && c<='9'){
                continue;
            }
            else{
                return false;
            }
        }
        return vow && cons;
    }
};
