// proficient
/*
    countAndSay(n) = RLE(countAndSay(n-1))
*/
class Solution {
  public:
	string RLE(string s) {
		if (s.length() == 1)
			return "11";
		// loop s calculate its number of consecutive char
		char cur_c = s[0];
		int cnt = 0;
		string res;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == cur_c) {
				++cnt;
			} else {
				res += to_string(cnt);
				res += cur_c;
				// restore cnt
				cnt = 1;
				// next count char
				cur_c = s[i];
			}
		}
		// 最後要再算一次
		res += to_string(cnt);
		res += cur_c;
		return res;
	}
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		return RLE(countAndSay(n - 1));
	}
};