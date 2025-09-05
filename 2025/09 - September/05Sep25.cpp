//    https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int numOfOperations = 1; ; numOfOperations++) {
            long long num = num1 - numOfOperations * 1LL * num2;
            if(numOfOperations > num) return -1;  
            if(__builtin_popcountll(num) <= numOfOperations) return numOfOperations;
        }
        return -1;
    }
};
