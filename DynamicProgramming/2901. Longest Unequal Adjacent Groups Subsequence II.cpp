/*
    1. dp[i] 往前看 j 個尋找 max(dp[j]), dp[i] = max(dp[j]) + 1
    dp[pair<(i, 上一個j)>]
    每次比較都是
    1. same length?
    2. is hamming distance ?
    3. group 不同?

    O(n^2)
*/
class Solution {
  public:
	vector<string> getWordsInLongestSubsequence(vector<string> &words,
	                                            vector<int> &groups) {
		vector<pair<int, int>> dp(words.size());
		dp[0] = {1, -1};
		for (int i = 1; i < words.size(); ++i) {
			pair<int, int> prefix = {0, -1};
			for (int j = i - 1; j >= 0; --j) {
				if (words[i].length() != words[j].length() ||
				    groups[i] == groups[j])
					continue;
				if (words[i] == words[j]) {
					if (dp[j].first > prefix.first)
						prefix = {dp[j].first, j};
					continue;
				}
				int ham_dis = 0;
				for (int k = 0; k < words[i].length(); ++k) {
					if (words[i][k] != words[j][k])
						++ham_dis;
					if (ham_dis > 1)
						break;
				}
				if (ham_dis <= 1 && dp[j].first > prefix.first)
					prefix = {dp[j].first, j};
			}
			dp[i] = {prefix.first + 1, prefix.second};
		}
		pair<int, int> max_subseq = {INT_MIN, -1}; // {num, last_idx}
		int idx = -1;
		for (int i = 0; i < dp.size(); ++i) {
			cout << dp[i].first << " ";
			if (dp[i].first > max_subseq.first) {
				max_subseq = dp[i];
				idx = i;
			}
		}
		cout << endl;
		// 從這個index往前找
		vector<string> res;
		while (idx != -1) {
			res.push_back(words[idx]);
			idx = dp[idx].second;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};