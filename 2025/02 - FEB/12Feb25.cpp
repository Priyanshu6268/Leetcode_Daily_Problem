//    https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for (int num : nums) {
            int sum = digSum(num);
            map[sum].push_back(num);
        }
        int maxSum = -1;
        for (auto& [key, arr] : map) {
            if (arr.size() >= 2) {
                nth_element(arr.begin(), arr.end() - 1, arr.end());
                nth_element(arr.begin(), arr.end() - 2, arr.end());
                maxSum = max(maxSum, arr[arr.size() - 1] + arr[arr.size() - 2]);
            }
        }
        return maxSum;
    }
    int digSum(int x) {
        int sum = 0;
        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};
