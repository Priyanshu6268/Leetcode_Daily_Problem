//    https://leetcode.com/problems/kth-distinct-string-in-an-array/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map <string,int> mpp;
        for(auto &word :arr)
            mpp[word]++;
        for(auto &word : arr)
            if(mpp[word]==1 && --k==0)
                return word;
        return "";
    }
};
