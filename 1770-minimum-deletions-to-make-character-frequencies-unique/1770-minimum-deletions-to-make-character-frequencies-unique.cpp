class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> count;
        int d = 0;
       unordered_set<int> used;
        
        for (char c : s) {
            count[c]++;
        }
        
        for (auto& let : count) {
            int freq = let.second;
            while (freq > 0 && used.find(freq) != used.end()) {
                freq--;
                d++;
            }
            used.insert(freq);
        }
        
        return d;
    }
};