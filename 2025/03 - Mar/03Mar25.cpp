//    https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> beforePivot, afterPivot, peas;
        for(int i: nums)
            if(i<pivot)
                beforePivot.push_back(i);
            else if(i == pivot)
                peas.push_back(i);
            else
                afterPivot.push_back(i);
        beforePivot.insert(beforePivot.end(), peas.begin(), peas.end());
        beforePivot.insert(beforePivot.end(), afterPivot.begin(), afterPivot.end());
        return beforePivot;
    }
};
