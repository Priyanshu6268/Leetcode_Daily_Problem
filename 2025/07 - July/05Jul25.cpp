//    https://leetcode.com/problems/find-lucky-integer-in-an-array/description/
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> count;
        for(auto &val : arr)
            count[val] += 1;

        int ans = -1;
        for(auto [val, cnt] : count)
            if(val == cnt) 
                ans = max(ans, val);
        return ans; 
    }
};
