class Solution {
public:
        static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> m;
        int res = 0;
        for (string a : words) {
            int l=0;
            for (int i = 0; i < a.length(); i++) {
                string temp = a;
                temp.erase(i, 1);
                l = max(l,m[temp]+1);
            }
            m[a] = l;
            res = max(res,l);
        }
        return res;
    }
}; 