/*
    1. brutal force: 每個lower~upper都去查看有沒有overflow, O(n*m), n = number
   of difference, m = upper - lower

    2. 先計算differences 的累加min/max 分別跟lower/upper 計算lower bound, upper
   bound, bound range為 num of possible hidden sequence
*/
class Solution {
  public:
	int numberOfArrays(vector<int> &differences, int lower, int upper) {
		long long sum = 0;
		long long min_sum = 0;
		long long max_sum = 0; // 第 0個位置的prefix 為 0, 一開始sum本就該為0
		for (int i = 0; i < differences.size(); ++i) {
			sum += differences[i];
			min_sum = min(min_sum, sum);
			max_sum = max(max_sum, sum);
		}
		long long lower_bound = lower - min_sum;
		long long upper_bound = upper - max_sum;

		return max(0LL, upper_bound - lower_bound + 1);
	}
};