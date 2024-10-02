//    https://leetcode.com/problems/rank-transform-of-an-array/description/
class ValueIndex {
public:
    int val;
    int index;

    ValueIndex(int v, int i) : val(v), index(i) {}
};

struct compare {
    bool operator()(const ValueIndex& a, const ValueIndex& b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<ValueIndex, vector<ValueIndex>, compare> pq;

        // Fill the priority queue
        for (int i = 0; i < arr.size(); i++) {
            pq.push(ValueIndex(arr[i], i));
        }

        int rank = 0;
        int prev = INT_MIN;

        // Transform the array with ranks
        while (!pq.empty()) {
            ValueIndex temp = pq.top();
            pq.pop();
            
            if (temp.val > prev) {
                rank++;
            }
            
            arr[temp.index] = rank;
            prev = temp.val;
        }

        return arr;
    }
};
