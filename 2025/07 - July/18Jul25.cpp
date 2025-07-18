//        https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int size = nums.size();
        vector<long long> left(size, 0);
        priority_queue<int> maxHeap;
        long long sumLeft = 0;
         for (int i = 0; i < size; ++i) {
            maxHeap.push(nums[i]);
            sumLeft += nums[i];
            if (maxHeap.size() > n) {
                sumLeft -= maxHeap.top();
                maxHeap.pop();
            }
            if (i >= n - 1)
                left[i] = sumLeft;
        }
         vector<long long> right(size, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumRight = 0;
     for (int i = size - 1; i >= 0; --i) {
            minHeap.push(nums[i]);
            sumRight += nums[i];
            if (minHeap.size() > n) {
                sumRight -= minHeap.top();
                minHeap.pop();
            }
            if (i <= 2 * n)
                right[i] = sumRight;
        }
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, left[i] - right[i + 1]);
        }

        return res;
    }
};
