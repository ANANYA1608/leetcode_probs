class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> g;
        
        for (auto& ticket : tickets) {
            g[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto& [_, d] : g) {
            sort(d.rbegin(), d.rend());
        }
        
        vector<string> v;
        
        function<void(const string&)> dfs = [&](const string& airport) {
            while (!g[airport].empty()) {
                string next = g[airport].back();
                g[airport].pop_back();
                dfs(next);
            }
            v.push_back(airport);
        };
        
        dfs("JFK");
        reverse(v.begin(), v.end());
        
        return v;
    }
};