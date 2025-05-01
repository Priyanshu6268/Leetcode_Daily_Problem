//    https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/
class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int>ws(workers.end()-k,workers.end());
        int p = pills;
        for(int i=k-1;i>=0;i--){
            int task = tasks[i];
            auto it = ws.lower_bound(task);
            if(it != ws.end()){
                ws.erase(it);
            }
            else{
                if(p==0)return false;
                auto it = ws.lower_bound(task-strength);
                if(it==ws.end())return false;
                ws.erase(it);
                p--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size()), answer = 0;

        while (left <= right) {
            int mid = (left+right)/2;
            if(canAssign(mid,tasks,workers,pills,strength)){
                answer = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return answer;
    }
};
