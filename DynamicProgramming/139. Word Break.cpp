// proficient
/*
    dp[i] 代表這個index是否能夠被worddict seperate

    j = 0 ~ i - 1
    dp[i] = dp[j] && substr(j+1, i - j) in dictionary

    time complexity O(n^3)

    sol 2. 從後面做回來, 如果每次 s[i + word.size()] in wordDict 並且 dp[i +
   word.size] = true(之前這個位置可以seperate), dp[i] = true

    s.length -> n
    worddict length -> m
    max word size -> t
    time complexity
*/
class Solution {
  public:
	bool wordBreak(string s, vector<string> &wordDict) {
		int n = s.length();
		vector<bool> dp(n, false); // idx is legal to seperate
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		for (int i = 0; i < n; ++i) {
			// index j = 0 先確認一次, 也就是直接這個index i seperate
			// cout << s.substr(0, i + 1) << endl;
			if (dict.find(s.substr(0, i + 1)) != dict.end()) {
				dp[i] = true;
				continue;
			}
			for (int j = i - 1; j >= 0; --j) {

				if (dp[j] && dict.find(s.substr(j + 1, i - j)) != dict.end()) {
					// cout << i << " " << j << " " << s.substr(j, i - j + 1) <<
					// endl;
					dp[i] = true;
					break;
				}
			}
		}
		for (int i = 0; i < dp.size(); ++i)
			cout << dp[i] << endl;
		return dp[n - 1];
	}
};