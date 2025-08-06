//      https://leetcode.com/problems/fruits-into-baskets-iii/description/
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        vector<long long> tree(4 * n);
        auto build = [&](auto&& self, int node, int start, int end) -> void {
            if (start == end) {
                tree[node] = b[start];
                return;
            }
            int mid = (start + end) / 2;
            self(self, 2 * node, start, mid);
            self(self, 2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        };
        build(build, 1, 0, n - 1);
        auto update = [&](auto&& self, int node, int start, int end, int idx, long long val) -> void {
            if (start == end) {
                tree[node] = val;
                return;
            }
            int mid = (start + end) / 2;
            if (idx <= mid)
                self(self, 2 * node, start, mid, idx, val);
            else
                self(self, 2 * node + 1, mid + 1, end, idx, val);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        };
        auto query = [&](auto&& self, int node, int start, int end, long long qty) -> int {
            if (tree[node] < qty) return -1;
            if (start == end) return start;
            int mid = (start + end) / 2;
            if (tree[2 * node] >= qty)
                return self(self, 2 * node, start, mid, qty);
            else
                return self(self, 2 * node + 1, mid + 1, end, qty);
        };
        int unplaced = 0;
        for (int qty : f) {
            int idx = query(query, 1, 0, n - 1, qty);
            if (idx == -1) {
                unplaced++;
            } else {
                update(update, 1, 0, n - 1, idx, -1LL);
            }
        }
        return unplaced;
    }
};
