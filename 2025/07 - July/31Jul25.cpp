//    https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        set<int> cur;

        for (int num : arr) {
            set<int> next;
            next.insert(num);

            for (int prev : cur) {
                next.insert(prev | num);
            }

            cur = next;

            for (int x : cur) {
                res.insert(x);
            }
        }
        return res.size();
    }
};
