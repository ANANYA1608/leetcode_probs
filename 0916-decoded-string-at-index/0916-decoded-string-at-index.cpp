class Solution {
public:
    std::string decodeAtIndex(string s, int k) {
        long long l = 0;
        int i = 0;
        
        while (l< k) {
            if (isdigit(s[i])) {
                l *= s[i] - '0';
            } else {
                l++;
            }
            i++;
        }
        
        for (int j = i - 1; j >= 0; j--) {
            if (isdigit(s[j])) {
                l /= s[j] - '0';
                k %= l;
            } else {
                if (k == 0 || k == l) {
                    return std::string(1, s[j]);  
                }
                l--;
            }
        }
        
        return "";
    }
};