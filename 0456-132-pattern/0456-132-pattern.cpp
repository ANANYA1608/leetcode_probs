class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> sk;
        int pat = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < pat) return true;
            while (!sk.empty() && sk.top() < nums[i]) {
                pat = sk.top();
                sk.pop();
            }
            sk.push(nums[i]);
        }
        return false;
    }
};