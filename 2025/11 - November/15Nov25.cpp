//    https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> zeros;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                zeros.push_back(i);
            }
        }
        zeros.push_back(n);
        for(int i = 0; i < n; i++) {
            int index = lower_bound(zeros.begin(), zeros.end(), i) - zeros.begin();
            if(zeros[index] < i) {
                continue;
            }
            int zerosCount = 0;
            int prevZeroIdx = i;
            for(int j = index; j < zeros.size() && j < (index + 201); j++) {
                int onesCount = zerosCount * zerosCount;
                int idx = max(i + zerosCount + onesCount - 1, prevZeroIdx);
                if(idx < zeros[j])
                    ans += zeros[j] - idx;
                prevZeroIdx = zeros[j];       
                zerosCount++;
            }
        }
        return ans;
    }
};
