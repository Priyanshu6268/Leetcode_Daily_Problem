//.    https://leetcode.com/problems/implement-router/description/
class Router {
public:
using Packet=array<int,3>;
    queue<Packet> que;
    int size;
    set<Packet> st;
    map<int,vector<int>> dist;
    Router(int memoryLimit) {
        size=memoryLimit;
    }
    void removeqpacket(Packet &t){
        *lower_bound(dist[t[1]].begin(),dist[t[1]].end(),t[2])=0;
        return ;
    }
    bool addPacket(int source, int destination, int timestamp) {
        Packet a={source,destination,timestamp};
        if(st.find(a)!=st.end()){
            return false;
        }
        que.push(a);
        dist[destination].push_back(timestamp);
        if(que.size()>size){
            Packet b=que.front();
            que.pop();
            st.erase(b);
            removeqpacket(b);
        }
        st.insert(a);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(que.empty()) return {};
        Packet a=que.front();
        que.pop();
        st.erase(a);
        removeqpacket(a);
        return {a[0],a[1],a[2]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
       auto & v=dist[destination];
        int count=upper_bound(v.begin(),v.end(),endTime)-
        lower_bound(v.begin(),v.end(),startTime);
        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
