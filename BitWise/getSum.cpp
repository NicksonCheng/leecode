/*
    a ^ b 計算相加
    (a & b) << 1 計算carry

    一直相加(^) 直到 carry == 0
*/
#include <iostream>
using namespace std;
class Solution {
  public:
	int getSum(int a, int b) {

		// a = target , b = carry

		while (b != 0) {
			int carry = (a & b) << 1;
			a ^= b;

			b = carry;
		}
		return a;
	}
};

int main() {
	Solution sol;
	cout << sol.getSum(5, -3) << endl;
}