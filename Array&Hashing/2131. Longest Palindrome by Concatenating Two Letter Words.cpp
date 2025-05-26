class Solution {
  public:
	int longestPalindrome(vector<string> &words) {
		int res = 0;
		unordered_map<string, int> word_map;
		bool same_add = false;

		for (string &s : words) {
			++word_map[s];
		}

		for (auto &[s, count] : word_map) {
			if (s[0] == s[1]) {
				// 對稱字串，例如 "gg"
				if (count % 2 == 0) {
					res += count * 2;
				} else {
					res += (count - 1) * 2;
					same_add = true; // 留一個放中間
				}
			} else {
				string rev = {s[1], s[0]};
				if (word_map.count(rev)) {
					int pair_count = min(count, word_map[rev]);
					res += pair_count * 4;
					word_map[rev] = 0; // 標記 rev 已處理
					word_map[s] = 0;
				}
			}
		}

		if (same_add)
			res += 2; // 中間放一個對稱字串

		return res;
	}
};
