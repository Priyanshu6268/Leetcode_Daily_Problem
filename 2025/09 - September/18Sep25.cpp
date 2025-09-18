//    https://leetcode.com/problems/design-task-manager/description/
class TaskManager {
public:
    unordered_map<int, pair<int, int>> ttoup;
    map<int, set<int>> ptot;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks) add(i[0], i[1], i[2]);
    }
    
    void add(int userId, int taskId, int priority) {
        ttoup[taskId]={userId, priority};
        ptot[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        int& p=ttoup[taskId].second;
        if(ptot[p].size()==1) ptot.erase(p);
        else ptot[p].erase(taskId);

        ptot[newPriority].insert(taskId);
        p=newPriority;
    }
    
    void rmv(int taskId) {
        int p=ttoup[taskId].second;
        if(ptot[p].size()==1) ptot.erase(p);
        else ptot[p].erase(taskId);
        ttoup.erase(taskId);
    }
    
    int execTop() {
        if(ptot.empty()) return -1;
        int task = *rbegin(rbegin(ptot)->second);
        int user = ttoup[task].first;
        rmv(task);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
