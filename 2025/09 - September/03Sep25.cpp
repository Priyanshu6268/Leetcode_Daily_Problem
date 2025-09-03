//    https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        for(int i=0; i<points.size(); i++){
            points[i][1]=(-1)*points[i][1];
        }
        sort(begin(points), end(points));
        for(int i=0; i<points.size(); i++){
            points[i][1]=(-1)*points[i][1];
        }
        int cnt=0;
        for(int i=0; i<points.size(); i++){
            int mini=-2e9;
            for(int j=i+1; j<points.size(); j++){
                if(points[i][1]>=points[j][1] && points[j][1]>mini){
                    cnt++;
                    mini=points[j][1];
                }
            }
        }
        return cnt;
    }
};
