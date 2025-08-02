//      https://leetcode.com/problems/rearranging-fruits/description/
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> mp1, mp2;
        for (auto x : basket1) mp1[x]++;
        for (auto x : basket2) mp2[x]++;

        set<int> all_keys;
        for (auto& [k, _] : mp1) all_keys.insert(k);
        for (auto& [k, _] : mp2) all_keys.insert(k);

        vector<pair<int, int>> v1, v2;

        for (int key : all_keys) {
            int count1 = mp1[key];
            int count2 = mp2[key];
            int total = count1 + count2;

            if (total % 2 != 0) return -1; 

            int diff = abs(count1 - count2) / 2;
            if (count1 > count2) {
                for (int i = 0; i < diff; i++) v1.push_back({key, 1});
            } else if (count2 > count1) {
                for (int i = 0; i < diff; i++) v2.push_back({key, 1});
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend()); 

        int minVal = min(*min_element(basket1.begin(), basket1.end()),
                         *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < v1.size(); ++i) {
            cost += min({v1[i].first, v2[i].first, 2 * minVal});
        }

        return cost;
    }
};
