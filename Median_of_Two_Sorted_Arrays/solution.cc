class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& A = nums1.size() > nums2.size() ? nums2: nums1;
    vector<int>& B = nums1.size() > nums2.size() ? nums1: nums2;
    
    // make sure n >= m
    int n = B.size();
    int m = A.size();
    int imin = 0;
    int imax = m;

    while (true) {
        int i = (imin + imax) / 2;
        int j = (m + n + 1) / 2 - i;

        if ((j == 0 || i == m || B.at(j - 1) <= A.at(i)) &&
            (i == 0 || j == n || A.at(i - 1) <= B.at(j))) {
            int maxLeft;
            if (i == 0) { maxLeft = B.at(j - 1); }
            else if (j == 0) { maxLeft = A.at(i - 1); }
            else { maxLeft = std::max(A.at(i - 1), B.at(j - 1)); }
            if ((m + n) %2 == 1) { return maxLeft; }
            
            int minRight;
            if (i == m) { minRight = B.at(j); }
            else if (j == n) { minRight = A.at(i); }
            else { minRight = std::min(A.at(i), B.at(j)); }
            
            return (minRight + maxLeft) / 2.0;
        } else if (j > 0 && i < m && B.at(j - 1) > A.at(i)) {
            imin = i + 1;
        } else if (i > 0 && j < n && A.at(i - 1) > B.at(j)) {
            imax = i - 1;
        }
    }
  }
};
