// solution
/*
 1. two pointer, 每次都從char去左右擴充, odd, even的palindromic都去看


 2. DP, recursive formula

 LPS(0,n) = LPS(1, n-1) + 2 -> if s[0] == s[n]
 LPS(0,n) = max(LPS(0,n-1), LPS(1,n))-> if s[0] != s[n]
*/
class Solution {
  public:
	string longestPalindrome(string s) {
		int n = s.length();
		if (n == 0)
			return "";
		string max_palin = "";
		for (int i = 0; i < n; ++i) {
			// odd palindromic, center expand
			int l = i;
			int r = i;
			while (l >= 0 && r < n && s[l] == s[r]) {
				// 優化: 可以先看是否比max_palin大
				int cur_len = r - l + 1;
				if (cur_len > max_palin.length())
					max_palin = s.substr(l, cur_len);
				--l;
				++r;
			}

			// even palindromic, center expand
			l = i;
			r = i + 1;
			while (l >= 0 && r < n && s[l] == s[r]) {
				// 優化: 可以先看是否比max_palin大
				int cur_len = r - l + 1;
				if (cur_len > max_palin.length())
					max_palin = s.substr(l, cur_len);
				--l;
				++r;
			}
		}
		return max_palin;
	}
};