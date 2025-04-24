class Solution {
  public:
	vector<int> plusOne(vector<int> &digits) {
		int size = digits.size();
		vector<int> res(size + 1);
		int plus_one = digits[size - 1] + 1;
		res[size] = plus_one % 10;
		int carry = plus_one / 10;
		for (int i = size - 2; i >= 0; --i) {
			plus_one = digits[i] + carry;
			res[i + 1] = plus_one % 10;
			carry = plus_one / 10;
		}
		if (carry > 0)
			res[0] = carry;
		else
			res.erase(res.begin());
		return res;
	}
};
