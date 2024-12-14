//      https://leetcode.com/problems/continuous-subarrays/description/
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        long long ans=0,i=0,j=0,n=nums.size();
        while(i<n) {
            ms.insert(nums[i]);
            while((*ms.rbegin()-*ms.begin())>2) {
                ms.erase(ms.find(nums[j++])); 
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
};
