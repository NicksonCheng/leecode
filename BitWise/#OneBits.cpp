class Solution {
  public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		for (int i = 0; i < 32; ++i) {
			cnt += (n & 1);
			n = n >> 1;
		}
		return cnt;
	}
};
