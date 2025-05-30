//      https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        dist1[node1] = 0;
        int v1 = node1;
        while(edges[v1] != -1 && dist1[edges[v1]] == -1) {
            dist1[edges[v1]] = dist1[v1] + 1;
            v1 = edges[v1];
        }
        vector<int> dist2(n, -1);
        dist2[node2] = 0;
        int v2 = node2;
        while(edges[v2] != -1 && dist2[edges[v2]] == -1) {
            dist2[edges[v2]] = dist2[v2] + 1;
            v2 = edges[v2];
        }
        int dist = INT_MAX;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                if (max(dist1[i], dist2[i]) < dist) {
                    dist = max(dist1[i], dist2[i]);
                    node = i;
                }
            }
        }
        return node;
    }
};
