//    https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/
class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        int ans = 0;
        long long new_k = k-1;
        for(int i = 63; i >= 0 ; i--){
            if((new_k>>i)&1){
                ans += ops[i];
            }
        }
        return char('a' + ans%26);
    }
};
