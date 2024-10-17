//    https://leetcode.com/problems/maximum-swap/description/
class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        // return 9973;
        int maxa = INT_MIN;
        int index;
        for(int i=0;i<nums.size()-1;i++){
            maxa = INT_MIN;
            for(int j=i+1;j<nums.size();j++){
                if(maxa<=nums[j]-'0'){
                    maxa = nums[j]-'0';
                    index = j;
                }
            }
            cout<<nums[i]-'0'<<endl<<nums[index]<<maxa<<endl;
            if(nums[i]-'0'<maxa){
                swap(nums[i],nums[index]);
                break;
            }
        }
        return stoi(nums);
    }
};
