/*
    每個right有兩個選擇, partition(left = right) or 繼續left下去
    time complexity(n * 2^n)

*/
class Solution {
  public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		vector<string> comb;
		dfs(s, comb, 0, 0);
		return res;
	}
	void dfs(string s, vector<string> &comb, int i, int j) {
		if (j >= s.length()) {
			if (i == j) // partiton成功
				res.push_back(comb);
			return;
		}
		// partition, check this part is palindrom or not

		if (isPalindrome(s, i, j)) {
			comb.push_back(s.substr(i, j - i + 1));
			dfs(s, comb, j + 1, j + 1);
			comb.pop_back();
		}

		// keep this substr
		dfs(s, comb, i, j + 1);
	}
	bool isPalindrome(string s, int l, int r) {
		while (l < r) {
			if (s[l] != s[r]) {
				return false;
			} else {
				++l;
				--r;
			}
		}
		return true;
	}
};
/*

/*
    version 2, 減少recursive數量

*/
class Solution {
  public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		vector<string> comb;
		dfs(s, comb, 0);
		return res;
	}
	void dfs(string s, vector<string> &comb, int l) {
		if (l >= s.length()) {
			res.push_back(comb);
			return;
		}
		for (int r = l; r < s.length(); ++r) {
			if (isPalindrome(s, l, r)) {
				// partition
				comb.push_back(s.substr(l, r - l + 1));
				dfs(s, comb, r + 1);
				comb.pop_back();
			}
		}
	}
	bool isPalindrome(string s, int l, int r) {
		while (l < r) {
			if (s[l] != s[r]) {
				return false;
			} else {
				++l;
				--r;
			}
		}
		return true;
	}
};
*/