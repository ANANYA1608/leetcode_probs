class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, cnt1 = 0, cnt2 = 0;
        
        for (auto num : nums) {
            if (c1 == num) cnt1++;
            else if (c2 == num) cnt2++;
            else if (cnt1 == 0) c1 = num, cnt1 = 1;
            else if (cnt2 == 0) c2 = num, cnt2 = 1;
            else cnt1--, cnt2--;
        }
         
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == c1) cnt1++;
            else if (num == c2) cnt2++;
        }
        
        vector<int> res;
        if (cnt1 > nums.size() / 3) res.push_back(c1);
        if (cnt2 > nums.size() / 3) res.push_back(c2);
        
        return res;
    }
};