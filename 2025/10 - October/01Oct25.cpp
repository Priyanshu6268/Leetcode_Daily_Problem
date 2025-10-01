//    https://leetcode.com/problems/water-bottles/
class Solution {
public:
    int numWaterBottles(int n, int num) {
        int ans = n  ;
        while(n>=num)
        {
            ans += n/num ;
            n = n/num + n%num ;
        }
        return ans ;
    }
};
