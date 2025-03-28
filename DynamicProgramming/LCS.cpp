// hint
/*
    1. char 有 match 就一起往前一步
    2. 沒有match 就比較各自往前的recursive 回來 誰的 subsequence比較大
*/
class Solution {
  public:
	int longestCommonSubsequence(string text1, string text2) {

		int n1 = text1.length();
		int n2 = text2.length();
		vector<vector<int>> table(n1, vector<int>(n2, -1));
		int max_subseq = dfs(table, text1, text2, 0, 0);
		return max_subseq;
	}
	int dfs(vector<vector<int>> &table, string text1, string text2, int i1,
	        int i2) {
		if (i1 == text1.length() || i2 == text2.length())
			return 0;
		if (table[i1][i2] != -1) {
			return table[i1][i2];
		}
		if (text1[i1] == text2[i2]) {
			table[i1][i2] = 1 + dfs(table, text1, text2, i1 + 1, i2 + 1);
			return table[i1][i2];
		}
		table[i1][i2] = max(dfs(table, text1, text2, i1 + 1, i2),
		                    dfs(table, text1, text2, i1, i2 + 1));
		return table[i1][i2];
	}
};
