class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of both input arrays.
        int a = nums1.size();
        int b = nums2.size();

        // Merge the arrays into a single sorted array.
        vector<int> one;
        for (int i = 0; i < a; i++) {
            one.push_back(nums1[i]);
        }
        for (int i = 0; i < b; i++) {
            one.push_back(nums2[i]);
        }

        // Sort the merged array.
        sort(one.begin(), one.end());

        // Calculate the total number of elements in the merged array.
        int t = one.size();

        if (t % 2 == 1) {
            // If the total number of elements is odd, return the middle element as the median.
            return static_cast<double>(one[t / 2]);
        } else {
            // If the total number of elements is even, calculate the average of the two middle elements as the median.
            int mid1 = one[t / 2 - 1];
            int mid2 = one[t / 2];
            return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0;
        }
    }
};