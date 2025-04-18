//    https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/
using PII = pair< int, int> ;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size() ;
        priority_queue<int, vector<int>, greater<>> empty ;
        priority_queue<PII, vector<PII>, greater<>> used ;
        for(int i = 0; i < n; i++)
            empty.push(i) ;
        
        for(int i = 0; i < n; i++)
            times[i].push_back(i) ;
        
        sort( times.begin(), times.end() ) ;
        
        for(auto t : times)
        {
            int start = t[0] ;
            int end = t[1] ;
            int ID = t[2] ;
            
            while(!used.empty() && used.top().first <= start)
            {
                empty.push(used.top().second ) ;
                used.pop() ;
            }
            
            int chair = empty.top() ;
            empty.pop() ;
            if(targetFriend == ID)
                return chair ;
            used.push({end, chair}) ;
        }
        return -1 ;
    }
};
