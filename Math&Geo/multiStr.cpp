class Solution {
  public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		// zero padding
		vector<int> digit_list(num1.length() + num2.length(), 0);

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < num1.length(); ++i) {
			for (int j = 0; j < num2.length(); ++j) {
				int digit = (num1[i] - '0') * (num2[j] - '0');

				// remember that there are multiple multiply in each digit, so
				// we need to accumulate
				digit_list[i + j] += digit;
				digit_list[i + j + 1] += digit_list[i + j] / 10;
				digit_list[i + j] %= 10;
			}
		}
		stringstream res;
		int n = digit_list.size() - 1;
		while (n >= 0 && digit_list[n] == 0) {
			--n;
		}

		while (n >= 0) {
			res << digit_list[n];
			--n;
		}
		return res.str();
	}
};
