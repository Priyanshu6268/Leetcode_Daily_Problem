//    https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> ans;
        for(int i=0, j=0; i<n1|| j<n2; ){
            int id1=(i==n1)?2000:nums1[i][0], id2=(j==n2)?2000:nums2[j][0];
            if (id1==id2) 
                ans.push_back({id1, nums1[i][1]+nums2[j][1]}), i++, j++;
            else if (id1< id2) 
                ans.push_back(nums1[i]), i++;
            else 
                ans.push_back(nums2[j]), j++;
        }
        return ans;
    }
};
