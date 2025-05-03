//    https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        if (tops.size() != bottoms.size())
            return -1;
        const int top = tops.front();
        const int bottom = bottoms.front();
        const int n = tops.size();        
        int res = numeric_limits<int>::max();
        for (const int domino: {top, bottom})
        {
            int cnt0 = 0;
            int cnt1 = 0;
            bool valid = true;
            for (int i = 0; i < n; ++ i)
            {
                if (tops[i] != domino && bottoms[i] != domino)
                {
                    valid = false;
                    break;
                }
                if (tops[i] != domino)
                    ++ cnt0;
                if (bottoms[i] != domino)
                    ++ cnt1;
            }
            if (valid)
            {
                res = min({res, cnt0, cnt1});
            }
        }
        return res == numeric_limits<int>::max() ? -1 : res;
    }
};
