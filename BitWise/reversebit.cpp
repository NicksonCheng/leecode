class Solution {
  public:
	uint32_t reverseBits(uint32_t n) {
		int num_bit = 32;
		uint32_t res = 0;

		// check every bit and add to (num_bit - 1 - i)[reverse bit]
		for (int i = 0; i <= num_bit; ++i) {
			int curr_bit = n & 1;
			int bit_pos = curr_bit << (num_bit - 1 - i);
			res |= bit_pos;
			n >>= 1;
		}
		return res;
	}
};
