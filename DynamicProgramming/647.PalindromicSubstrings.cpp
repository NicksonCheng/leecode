/*
    1. two pointer從中間擴充odd, even


    2. sliding window 滑動尋找palindromic, 並且用dp儲存目前substring(i,j)
   是否palindromic
*/
class Solution {
  public:
	int countSubstrings(string s) {
		int n = s.length();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int count = 0;
		for (int r = 0; r < n; ++r) {
			for (int l = r; l >= 0; --l) {
				// check if its substring is palingromic(odd, even case is all
				// include)
				if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
					++count;
					dp[l][r] = true;
				}
			}
		}
		return count;
	}
};