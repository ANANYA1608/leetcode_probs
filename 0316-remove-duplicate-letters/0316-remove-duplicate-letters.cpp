class Solution {
public:
    string removeDuplicateLetters(string s) {
        int l = s.size();
        string res = "";
        unordered_map<char, int> m;
        unordered_map<char, bool> Vis;
        stack<int> S;
        
        for (auto c : s) {
            if (m.find(c) == m.end()) m[c] = 1;
            else m[c]++; 
        }
        for (unordered_map<char, int>::iterator it=m.begin(); it!=m.end(); it++) Vis[it->first] = false;
        
        cout<<m.size()<<Vis.size()<<endl;
        for (int i=0; i<l; i++) {
            m[s[i]]--;
            if (Vis[s[i]] == true) continue;
            
            while (!S.empty() and s[i] < s[S.top()] and m[s[S.top()]] > 0) {
                Vis[s[S.top()]] = false;
                S.pop();
            }
            S.push(i);
            Vis[s[i]] = true;
        }
        while (!S.empty()) {
            res = s[S.top()] + res;
            S.pop();
        }
        return res;
    }
};


