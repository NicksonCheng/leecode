// 1. 先找大鈔
class Solution {
  public:
	bool lemonadeChange(vector<int> &bills) {
		vector<int> cache_register(3, 0);

		for (int &b : bills) {
			int return_money = 0;
			if (b == 5) {
				++cache_register[0];

			} else if (b == 10) {

				return_money = 5;
				while (cache_register[0] > 0 && return_money > 0) {
					return_money -= 5;
					--cache_register[0];
				}
				if (return_money > 0)
					return false;
				++cache_register[1];
			} else {

				return_money = 15;
				while (cache_register[1] > 0 && return_money > 0 &&
				       return_money > 10) {

					return_money -= 10;
					--cache_register[1];
				}
				while (cache_register[0] > 0 && return_money > 0) {
					return_money -= 5;
					--cache_register[0];
				}
				if (return_money > 0)
					return false;
				++cache_register[2];
			}
		}
		return true;
	}
};