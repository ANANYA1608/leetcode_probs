class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int t = 0, n = nums.size();
        for (int i : nums) t += i;
        t -= x;
        
        if (t == 0) return n;
        
        int maxlen = 0, cur = 0, l = 0;
        
        for (int r = 0; r < n; ++r) {
            cur += nums[r];
            while (l <= r && cur> t) {
                cur -= nums[l];
                l++;
            }
            if (cur == t) {
                maxlen = max(maxlen, r - l + 1);
            }
        }
        
        return maxlen ? n - maxlen : -1;
    }
};