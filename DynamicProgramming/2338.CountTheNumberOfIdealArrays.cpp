
/*
1. recursive, 0~maxValue 作為start, 每次都往前arr[i]的倍數,
直到超過maxValue或是超過n time complexity O(maxValue ^ n)

2.  DP, top-down 下去, 每個cur_idx 都會有cur_val的數量,
用table去儲存table[cur_idx][cur_val], 每個 cur_idx 會走一次這個遞迴（最多 n
層），每層又最多對 cur_val 做 log(maxValue) 級別的 work： O(n * maxValue *
log(maxValue)) ​
*/
class Solution {
  public:
	int modulo = 1e9 + 7;
	int idealArrays(int n, int maxValue) {
		vector<vector<int>> table(n + 1, vector<int>(maxValue + 1, -1));

		int count = 0;
		for (int i = 1; i <= maxValue; ++i)
			count = (count + recursive(table, n, maxValue, 1, i)) % modulo;
		return count;
	}
	int recursive(vector<vector<int>> &table, int n, int maxValue, int cur_idx,
	              int cur_val) {
		if (cur_idx == n)
			return 1;

		if (table[cur_idx][cur_val] != -1)
			return table[cur_idx][cur_val];

		// num[i] dividable by num[i-1]
		int count = 0;
		for (int val = cur_val; val <= maxValue; val += cur_val) {
			count = (count + recursive(table, n, maxValue, cur_idx + 1, val)) %
			        modulo;
		}
		table[cur_idx][cur_val] = count;
		return count;
	}
};

/* Bottom-Up + Combinatorics 解法*/
class Solution {
  public:
	const int MOD = 1e9 + 7;
	vector<vector<int>> dp;
	vector<int> factorial, invFactorial;

	int idealArrays(int n, int maxValue) {
		int maxLen =
		    14; // 只要到 log2(maxValue)，最長不會超過 14（因為每次乘以2以上）
		dp = vector<vector<int>>(maxValue + 1, vector<int>(maxLen + 1, 0));

		// dp[val][len]: 長度為 len，最後一項是 val 的 ideal array 數量
		for (int val = 1; val <= maxValue; ++val) {
			dp[val][1] = 1;
		}

		for (int len = 2; len <= maxLen; ++len) {
			for (int val = 1; val <= maxValue; ++val) {
				for (int mult = 2 * val; mult <= maxValue; mult += val) {
					dp[mult][len] = (dp[mult][len] + dp[val][len - 1]) % MOD;
				}
			}
		}

		// 預處理組合數
		initComb(n);

		long long res = 0;
		for (int val = 1; val <= maxValue; ++val) {
			for (int len = 1; len <= maxLen; ++len) {
				if (dp[val][len] == 0)
					continue;
				long long comb = nCr(n - 1, len - 1);
				res = (res + dp[val][len] * comb % MOD) % MOD;
			}
		}

		return res;
	}

	void initComb(int n) {
		factorial.resize(n + 1);
		invFactorial.resize(n + 1);

		factorial[0] = 1;
		for (int i = 1; i <= n; ++i)
			factorial[i] = 1LL * factorial[i - 1] * i % MOD;

		invFactorial[n] = modinv(factorial[n]);
		for (int i = n - 1; i >= 0; --i)
			invFactorial[i] = 1LL * invFactorial[i + 1] * (i + 1) % MOD;
	}

	int nCr(int n, int r) {
		if (r > n || r < 0)
			return 0;
		return 1LL * factorial[n] * invFactorial[r] % MOD *
		       invFactorial[n - r] % MOD;
	}

	int modinv(int x) { return modpow(x, MOD - 2); }

	int modpow(int x, int p) {
		int res = 1;
		while (p) {
			if (p & 1)
				res = 1LL * res * x % MOD;
			x = 1LL * x * x % MOD;
			p >>= 1;
		}
		return res;
	}
};
