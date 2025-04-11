//      https://leetcode.com/problems/count-symmetric-integers/description/
class Solution {
    bool check(int num){
        string s = to_string(num);
         if(s.size()%2!=0){
            return false;
         }

         int m = s.size()/2;
         int sum =0;
         for(int i =0; i<m; i++){
              sum += s[i]-'0';
         }
         int sum1 =0;
         for(int i =m; i<s.size(); i++){
              sum1 += s[i]-'0';
         }
        return sum ==sum1;
        
    }
public:
    int countSymmetricIntegers(int low, int high) {
        
        int count =0;
        for(int i = low ; i<=high; i++){
            if(check(i)){
                count++;
            }
        }
        return count;
    }
};
