// solution
/*
    每次divisor >> 1(x2) 直到超過dividend, 然後dividend 一次扣掉所有divisor,
   loop 直到 dividend < divisor
*/
class Solution {
  public:
	int divide(int dividend, int divisor) {
		// abs(INT_MIN) will overflow, need to hand it
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		long long a = abs((long long)dividend);
		long long b = abs((long long)divisor);

		long long res = 0;
		while (a >= b) {
			long long cur_d = 1;
			long long tmp_divisor = b; // need to loop every time
			while ((tmp_divisor <<= 1) < a) {
				cur_d <<= 1;
			}
			a -= (tmp_divisor >> 1); // substract current divisor remained a
			res += cur_d;
		}
		bool same_sign = (dividend > 0) == (divisor > 0);
		return same_sign ? res : -res;
	}
};