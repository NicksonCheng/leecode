class Solution {
  public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
		// Start from the end of both arrays
		int p1 = m - 1;    // pointer for nums1
		int p2 = n - 1;    // pointer for nums2
		int p = m + n - 1; // pointer for merged array

		// While there are elements to compare in both arrays
		while (p2 >= 0 && p1 >= 0) {
			if (nums1[p1] > nums2[p2]) {
				nums1[p] = nums1[p1];
				p1--;
			} else {
				nums1[p] = nums2[p2];
				p2--;
			}
			p--;
		}

		// If there are remaining elements in nums2
		while (p2 >= 0) {
			nums1[p] = nums2[p2];
			p2--;
			p--;
		}

		// No need to handle remaining nums1 elements as they're already in
		// place
	}
};