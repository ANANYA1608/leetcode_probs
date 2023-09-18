class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> row;
        for (int i = 0; i < mat.size(); ++i) {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            row.push_back({strength, i});
        }
        
        sort(row.begin(), row.end());
        
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(row[i].second);
        }
        
        return res;
    }
};