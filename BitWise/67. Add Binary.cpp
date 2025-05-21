/*
    1. 從a,b tail去做, xor(+) and(carry), 如果carry是1 則用 |去算下一個carry
*/
class Solution {
  public:
	string addBinary(string a, string b) {
		int l_a = a.length();
		int l_b = b.length();
		int carry = 0;
		string res = "";
		while (l_a > 0 && l_b > 0) {
			int a_bit = a[l_a - 1] - '0';
			int b_bit = b[l_b - 1] - '0';
			// cout << a_bit << b_bit << carry << endl;
			res = to_string((a_bit ^ b_bit ^ carry)) + res;
			if (carry == 1) {
				carry = a_bit | b_bit;
			} else
				carry = a_bit & b_bit;

			--l_a;
			--l_b;
		}
		while (l_a > 0) {
			int a_bit = a[l_a - 1] - '0';
			res = to_string(a_bit ^ carry) + res;
			carry = a_bit & carry;
			--l_a;
		}
		while (l_b > 0) {
			int b_bit = b[l_b - 1] - '0';
			res = to_string(b_bit ^ carry) + res;
			carry = b_bit & carry;
			--l_b;
		}
		if (carry > 0)
			res = "1" + res;
		return res;
	}
};