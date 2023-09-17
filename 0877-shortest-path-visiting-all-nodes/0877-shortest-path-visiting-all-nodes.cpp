class Solution {
    struct State {
     int m, node, dis;
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis = (1 << n) - 1;
        queue<State> q;
        unordered_set<int> visited;
        
        for (int i = 0; i < n; ++i) {
            q.push({1 << i, i, 0});
            visited.insert((1 << i) * 16 + i);
        }
        
        while (!q.empty()) {
            State cur = q.front(); q.pop();
            
            if (cur.m == vis) {
                return cur.dis;
            }
            
            for (int neig : graph[cur.node]) {
                int new_m = cur.m | (1 << neig);
                int hash = new_m * 16 + neig;
                
                if (visited.find(hash) == visited.end()) {
                    visited.insert(hash);
                    q.push({new_m, neig, cur.dis + 1});
                }
            }
        }
        
        return -1;
    }
};