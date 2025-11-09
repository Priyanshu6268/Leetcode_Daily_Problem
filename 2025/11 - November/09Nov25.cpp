//    https://leetcode.com/problems/count-operations-to-obtain-zero/description/
class Solution {
public:
    void solve(int& num1, int& num2, int& count){
        if(num1 <= 0 || num2 <= 0 ) return;
        if(num1>num2){
            num1 = num1-num2;
            count++;
        }else{
            num2 = num2-num1;
            count++;
        }

    }
    
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 && num2){
        solve(num1,num2,count);
        }
        return count;
    }
};
