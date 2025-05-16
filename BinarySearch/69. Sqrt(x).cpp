/*
    0 ~ x find lower bound m * m >= x
*/
class Solution {
  public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		long long l = 1;
		long long r = x;
		while (l < r) {
			long long m = (l + r) / 2;
			long long sqrt = m * m;

			// upper bond
			if (sqrt > x)
				r = m;
			else
				l = m + 1;
		}
		return r * r == x ? r : r - 1;
	}
};