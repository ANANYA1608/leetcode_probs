class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        vector<vector<int>> memo(a, vector<int>(b, INT_MIN));
        
        function<int(int, int)> dp = [&](int i, int j) {
            if (i == a || j == b) {
                return INT_MIN;
            }
            
            if (memo[i][j] != INT_MIN) {
                return memo[i][j];
            }
            
            memo[i][j] = max(
                nums1[i] * nums2[j] + max(dp(i + 1, j + 1), 0),
                max(dp(i + 1, j), dp(i, j + 1))
            );
            
            return memo[i][j];
        };
        
        return dp(0, 0);
    }
};