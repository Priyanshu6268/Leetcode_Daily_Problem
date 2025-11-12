//    https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        int ones = 0;
        for(int i = 0;i<n;i++)ones+=nums[i]==1;
        
        if(ones)return n-ones;
        
        for(int i = 0;i<n;i++){
            int gcd = 0;
            
            for(int j = i;j<n;j++){
                gcd = __gcd(gcd,nums[j]);
                
                if(gcd == 1){
                    int len = (j-i)+1;
                    ans = min(ans,(len-1)+(n-1));
                }
            }
            
         
        
        }
        if(ans == 1e9)ans = -1;
        return ans;
        
    }
};
