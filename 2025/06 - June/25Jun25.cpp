//    https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long a=-10000000000;
        long long b=10000000000;
        while(a<=b){
            long long mid=(a+b)/(long long)2;
            long long t=binsearch(nums1,nums2,mid);
            
            if(t<k){
                a=mid+1;
            }
            else{
                b=mid-1;
            }

        }
        return b;
    }
    long long binsearch(vector<int>& nums1, vector<int>& nums2, long long tar){
        long long res=0; 
        for(int i=0;i<nums1.size();i++){
            long long t=binsearch2(nums2,nums1[i],tar);
            res+=t;
        }
        return res;

    }
    long long binsearch2(vector<int>& nums2,long long tar2,long long tar){
        int a=0;
        int b=nums2.size()-1;
        if(tar2>0){
        while(a<=b){
            int mid=(a+b)/2;
            long long g=tar2*(long long)nums2[mid];
            if(g<tar){
                a=mid+1;
            }
            else{
                b=mid-1;
            }
        }
        }
        else{
            while(a<=b){
                int mid=(a+b)/2;
                long long g=tar2*(long long)nums2[mid];
                if(g<tar){
                    b=mid-1;
                }
                else{
                    a=mid+1;
                }
                
            }
            return nums2.size()-a;

        }
        return b+1;

    }
};
