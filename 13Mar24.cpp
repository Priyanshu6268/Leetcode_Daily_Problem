//    https://leetcode.com/problems/find-the-pivot-integer/
class Solution {
public:
    int pivotInteger(int n) {
        
        int runningSum = 0, total = n*(n+1)/2;
        for(int i = 1; i <= n; ++i) {
            int left = runningSum;
            int right = total-runningSum-i;
            if (left == right) return i;
            runningSum += i; 
        }
        return -1;
    }
};
