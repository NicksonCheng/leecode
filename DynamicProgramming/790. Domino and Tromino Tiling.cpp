// hint
/*
    dp[i-1] : 直的domino
    dp[i-2] : 兩個橫的domino
    d[i-3]~ dp[0]: tromino(鏡像包含2種)

 formula dp[i] = dp[i-1]+dp[i-2]+2*(dp[i-3]+dp[i-4]+…+dp[0])

  把 dp[i-3] 拿出來變成
 dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-3]+2*(dp[i-4]+dp[i-5]+…+dp[0])
而 dp[i-1] 的計算式是
 dp[i-2]+dp[i-3]+2*(dp[i-4]+dp[i-5]+…+dp[0])
所以 DP 計算式就變成了，減少了迴圈計算的部份
 dp[i] = 2*dp[i-1]+dp[i-3]

https://kevinchung0921.medium.com/leetcode-解題紀錄-790-domino-and-tromino-tiling-7c36f7a3ac1b
*/
class Solution {
  public:
	long long modulo = 1e9 + 7;
	int numTilings(int n) {
		vector<int> dp(3, 0);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		if (n <= 2)
			return dp[n];
		for (int i = 3; i <= n; ++i) {
			dp.push_back(((2 * dp[i - 1]) % modulo + dp[i - 3]) % modulo);
		}
		return dp[n];
	}
};