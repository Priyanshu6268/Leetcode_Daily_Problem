//    https://leetcode.com/problems/check-if-n-and-its-double-exist/description/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        map<int,int>mp;
        mp[0] = -1;
        for(auto val:arr) mp[val]++;
        for(auto val:arr)
        {
            if(val%2) 
            {
                if(mp[val+val]) return true;
            }
            else if(mp[val/2]) return true;
        }
        return false;
    }
};
