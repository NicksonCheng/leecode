/*
    快速冪方法, 透過直接去乘2進位出現"1"的地方,
   題目的問題為(5^num_even*4^num_odd) % modulo
   因爲bit>>=1 每次都相當於/2 去計算, time complexity為O(logn)
*/
class Solution {
  public:
	long long modulo = 1e9 + 7;
	long long modulo_cnt(long long exp, long long base) {
		// define modulo

		// 快速冪(base^n = base^d1 * base^d2 * .....base^dn)
		long long cnt = 1;
		while (exp > 0) {
			// encount bit '1', then multiply base
			if ((exp & 1) > 0)
				cnt = (cnt * base) % modulo;
			// change base based on it digits
			base = (base * base) % modulo;
			// shift bits
			exp >>= 1;
		}
		return cnt;
	}
	int countGoodNumbers(long long n) {
		long long num_odd = n / 2;
		long long num_even = n - num_odd;

		return (modulo_cnt(num_even, 5) * modulo_cnt(num_odd, 4)) % modulo;
	}
};