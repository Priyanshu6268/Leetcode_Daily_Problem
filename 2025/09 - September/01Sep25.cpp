//    https://leetcode.com/problems/maximum-average-pass-ratio/description/
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double p, double t) {
            return (p + 1) / (t + 1) - p / t;
        };
        priority_queue<vector<double>> pq;
        for (auto& c : classes) {
            double p = c[0], t = c[1];
            pq.push({gain(p, t), p, t});
        }
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            double p = top[1] + 1, t = top[2] + 1;
            pq.push({gain(p, t), p, t});
        }
        double sum = 0;
        while (!pq.empty()) {
            auto c = pq.top(); pq.pop();
            sum += c[1] / c[2];
        }
        return sum / classes.size();
    }
};
