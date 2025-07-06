//    https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/
class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int, int> mappa;
public:

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int i: arr2)
            mappa[i]++;
    }
    
    void add(int index, int val) {
        mappa[arr2[index]]--;
        arr2[index] += val;
        mappa[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int num1: arr1){
            cnt += mappa[tot - num1];
        }
        return cnt;
    }
};
