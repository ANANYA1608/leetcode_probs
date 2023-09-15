int distance(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);
        unordered_map<int, int> heap;
        for(int i = 0; i < n; ++i) {
            heap[i] = INT_MAX; // Initialize all distances to infinity
        }
        heap[0] = 0; // Start node
        
        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
        min_heap.push({0, 0});
        
        int mst = 0;
        
        while (!min_heap.empty()) {
            auto [w, u] = min_heap.top();
            min_heap.pop();
            
            if (vis[u] || heap[u] < w) continue;
            
            vis[u] = true;
            mst += w;
            
            for (int v = 0; v < n; ++v) {
                if (!vis[v]) {
                    int new_distance = distance(points[u], points[v]);
                    if (new_distance < heap[v]) {
                        heap[v] = new_distance;
                        min_heap.push({new_distance, v});
                    }
                }
            }
        }
        
        return mst;
    }
};