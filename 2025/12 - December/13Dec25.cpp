//      https://leetcode.com/problems/coupon-code-validator/description/
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        auto validLine = [](const string& s) {
            return s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant";
        };
        vector<int> idx;
        for(int i = 0, n = code.size(); i < n; ++i){
            if(!isActive[i] || !validLine(businessLine[i]) || code[i].empty()) continue;
            bool valid = true;
            for(int j = 0, m = code[i].size(); j < m; ++j){
                if(!isalnum(code[i][j]) && code[i][j] != '_'){
                    valid = false;
                    break;
                }
            }
            if(valid) idx.push_back(i);
        }
        sort(idx.begin() , idx.end() , [&](const int& a , const int& b){
            return businessLine[a][0] < businessLine[b][0] || (businessLine[a][0] == businessLine[b][0] && code[a] < code[b]);
        });
        const int len = idx.size();
        vector<string> res;
        res.reserve(len);
        for(int i = 0; i < len; ++i) res.push_back(code[idx[i]]);
        return res;
    }
};
