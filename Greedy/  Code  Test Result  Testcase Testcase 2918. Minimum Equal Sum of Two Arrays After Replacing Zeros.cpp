/*
    先看大家的mini sum有沒有0, 沒有0的那邊如果還比較小就 -1
    如果大家都有0, 那就看哪邊的mini sum(0都設為1)比較大return 就好

    greedy 部分: 都假設0為1的時候即可, 因為比較小的那邊0可以變成別的達到match
    O(n)
*/
class Solution {
  public:
	long long minSum(vector<int> &nums1, vector<int> &nums2) {
		long long mini_sum1 = 0;
		long long mini_sum2 = 0;
		int count1_zero = 0;
		int count2_zero = 0;
		for (int &n : nums1) {
			if (n == 0) {
				++count1_zero;
				++mini_sum1;
			} else
				mini_sum1 += n;
		}
		for (int &n : nums2) {
			if (n == 0) {
				++count2_zero;
				++mini_sum2;
			} else
				mini_sum2 += n;
		}

		if (count1_zero == 0 && mini_sum1 < mini_sum2)
			return -1;
		if (count2_zero == 0 && mini_sum2 < mini_sum1)
			return -1;

		return max(mini_sum1, mini_sum2);
	}
};