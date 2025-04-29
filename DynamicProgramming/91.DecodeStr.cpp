/*
    1. recursive decode(n) = decode(n-1) + num_two_decode + num_one_decode
*/
class Solution {
  public:
	int numDecodings(string s) {
		vector<int> table(s.length(), -1);
		return recursive(s, 0, table);
	}
	int recursive(string s, int i, vector<int> &table) {
		// fail decode
		if (s[i] == '0')
			return 0;
		// successfully decode
		if (i == s.length())
			return 1;
		if (table[i] != -1)
			return table[i];
		int num_code = recursive(s, i + 1, table);

		if (i + 2 <= s.length()) {
			stringstream ss;
			int code;
			ss << s.substr(i, 2);
			ss >> code;
			if (code <= 26)
				num_code += recursive(s, i + 2, table);
		}

		table[i] = num_code;
		return table[i];
	}
};