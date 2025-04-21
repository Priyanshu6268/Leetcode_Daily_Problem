//    https://leetcode.com/problems/count-the-hidden-sequences/
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxi = 0, mini = 0, presum = 0;
        for(int i: differences){
            presum += i;
            maxi = max  (maxi, presum);
            mini = min(mini, presum);
        }
        return max(0LL, (upper - maxi) - (lower - mini) + 1);
    }
};
