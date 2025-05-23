// solution
/*
    每次divisor >> 1(x2) 直到超過dividend, 然後dividend 一次扣掉所有divisor,
   loop 直到 dividend < divisor
*/
class Solution {
  public:
	int divide(int dividend, int divisor) {
		// abs(INT_MIN) will overflow
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

/*
    sol 2. 不用long long 的方法(記得b << 31可能overflow)
    INTMIN / -1 會overflow, 這個例外要處理

    把dividend(a), divisor(b) 都轉為neg處理(INT_MIN比INT_MAX多1比較好操作)

    從bit 31 ~ 0 移動直到tmp_b(這次loop的b) >= a, a -= b, 移動的bit代表*2的次數,
   loop直到原始b >= a
*/
class Solution {
  public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		int a = dividend > 0 ? -dividend : dividend;
		int b = divisor > 0 ? -divisor : divisor;
		int res = 0;
		// we continue substract b by bit shift, every shift will multiple 2 in
		// divisor,
		for (int i = 31; i >= 0; --i) {
			int tmp = b << i;
			if ((b >= INT_MIN >> i) &&
			    tmp >= a) { // >= a的 i為我們需要的index, 記得要避免overflow neg
				// cout << b << " " << tmp << " " << a <<endl;
				// cout << i << endl;
				res += (1 << i);
				a -= tmp;
			}
		}
		if (res == INT_MIN)
			return res;
		// 最後要判斷sign
		bool same_sign = (dividend > 0) == (divisor > 0);
		return same_sign ? res : -res;
	}
};