//      https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       int left[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        int right[n];
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int total_water=0;
        for(int i=0;i<n;i++){
            total_water=total_water+(min(left[i],right[i])-height[i]);
        }
        return total_water;
    }
};
