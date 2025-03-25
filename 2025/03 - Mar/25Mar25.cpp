//    https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_intervals, y_intervals;
        for (auto& r : rectangles) {
            x_intervals.push_back({r[0], r[2]});
            y_intervals.push_back({r[1], r[3]});
        }
        return max(countDistinctSections(x_intervals), countDistinctSections(y_intervals)) >= 3;
    }

private:
    int countDistinctSections(vector<pair<int, int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int mergedCount = 0, lastEnd = -1;
        
        for (auto& [start, end] : intervals) {
            if (start >= lastEnd) {
                mergedCount++;
                lastEnd = end;
            } else {
                lastEnd = max(lastEnd, end);
            }
        }

        return mergedCount;
    }
};
