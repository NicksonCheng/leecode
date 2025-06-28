/*
    1. recursive to simulate all subsequence and check if it's decimal < k
        n = s.length
        time  for recursive O(2^n)
        time for change to decimal O(n)
        total time O(n * 2^n)

    2. greedy 直接看 '1' 的地方, 看增加pow(2, idx of '1') 使否 > k

*/
class Solution {
  public:
	int longestSubsequence(string s, int k) {
		int n = s.length();
		int number = 0;
		int cnt = 0;
		int power = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == '1') {
				if (number + power <= k) {
					number += power;
					++cnt;
				}
			} else
				++cnt;
			if (power <= k)
				power <<= 1;
		}
		return cnt;
	}
};
w