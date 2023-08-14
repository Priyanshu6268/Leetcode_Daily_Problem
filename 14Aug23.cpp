//.       https://leetcode.com/problems/kth-largest-element-in-an-array/description/
class Solution {
public:
    //using heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it :nums){
            pq.push(it);
        }
        while(k-- != 1){
            pq.pop();
        }
        return pq.top();
    }
};
