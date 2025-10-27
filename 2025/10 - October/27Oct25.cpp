//    https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr = 0, ans = 0;
        for(string b: bank){
            curr = count(b.begin(), b.end(), '1');
            if(curr != 0){
                ans += prev * curr;
                prev = curr;
            }
        }
        return ans;
    }
};
