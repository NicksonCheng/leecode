/*
    1. We find an offset for the current number based on the number before
   offset positions
   2. dp[i] = 1 + dp[i - offset]

   3. offset need to be updated after encount 2^i,  offset = 1,2,4,8,16,......
*/
class Solution {
  public:
	vector<int> countBits(int n) {
		vector<int> table(n + 1, -1);
		table[0] = 0;
		table[1] = 1;
		int offset = 1;
		for (int i = 2; i <= n; ++i) {
			if (i == offset * 2) {
				offset = i;
			}
			table[i] = 1 + table[i - offset];
		}
		return table;
	}
};
// 1 + offset bit
// 0->0000 -> 0
// 1->0001 -> 1
// 2->00"1"0 -> 1 + dp[n-2]
// 3->0011 -> 1 + dp[n-2]
// 4->0"1"00 -> 1 + dp[n-4]
// 5->0101 -> 1 + dp[n-4]. ex: just n-4 step + 1 bit
// 6->0110 -> 1 + dp[n-4]
// 7->0111 -> 1 + dp[n-4]
// 8->1000 -> 1 + dp[n-8]
