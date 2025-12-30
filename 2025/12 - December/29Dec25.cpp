//    https://leetcode.com/problems/pyramid-transition-matrix/
class Solution {
public:
    bool solve(int i, int j, vector<vector<char>> &v, unordered_map<string, vector<char>> &m){
        if(i<=j) --i, j=0;
        if(i==0 && j==0) return true;
        string key = {v[i][j], v[i][j+1]};
        bool valid=false;
        for(auto &x: m[key]){
            v[i-1][j] = x;
            valid = valid || solve(i, j+1, v, m);
        }
        return valid;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for(int i=0; i<allowed.size(); ++i){
            m[{allowed[i][0], allowed[i][1]}].push_back(allowed[i][2]);
        }
        int n=bottom.length();
        vector<vector<char>> v(n, vector<char>(n));
        for(int i=0; i<n; ++i) v[n-1][i] = bottom[i];
        return solve(n-1, 0, v, m);
    }
};
