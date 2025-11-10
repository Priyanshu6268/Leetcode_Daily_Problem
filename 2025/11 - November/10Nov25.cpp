//    https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        set<int> rem;
        int ans=0;
        for(auto& i:m){
            if(i.first==0){
                for(auto& it:i.second) rem.insert(it);
                continue;
            }
            int trav=0;
            while(trav<i.second.size()){
                int val=i.second[trav];
                auto it=rem.lower_bound(val);
                if(it==rem.end()){
                    ans++;
                    break;
                }else{
                    ans++;
                    int v=*it;
                    int idx=lower_bound(i.second.begin(),i.second.end(),v)-i.second.begin();
                    trav=idx;
                }
            }
            for(auto& it:i.second) rem.insert(it);
        }
        return ans;

    }
};
