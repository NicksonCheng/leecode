/*
    hashtable紀錄num 的正確位置, 每次跑hashtable路線直到cycle結束, swap = cycle
   - 1 全部num都要visit
*/
class Solution {
  public:
	int countDigits(int num) {
		int d = 0;
		while (num > 0) {
			d += num % 10;
			num /= 10;
		}
		return d;
	}
	int minSwaps(vector<int> &nums) {
		int n = nums.size();
		int swap_count = 0;
		unordered_map<int, int> num_pos;   // {num, correct index}
		vector<pair<int, int>> num_digits; // {digits_sum, num}
		vector<bool> visit(nums.size(), false);
		for (int &num : nums)
			num_digits.push_back({countDigits(num), num});
		sort(num_digits.begin(), num_digits.end(),
		     [](pair<int, int> &a, pair<int, int> &b) {
			     if (a.first == b.first)
				     return a.second < b.second;
			     else
				     return a.first < b.first;
		     });

		// record sorting position
		for (int i = 0; i < num_digits.size(); ++i) {
			num_pos[num_digits[i].second] = i;
		}

		// traverse hashtable to count the number of swap
		for (auto &np : num_pos) {
			if (visit[np.second])
				continue;
			int cur = nums[np.second];
			visit[np.second] = true;
			while (cur != np.first) {
				++swap_count;
				visit[num_pos[cur]] = true;
				cur = nums[num_pos[cur]];
			}
		}
		return swap_count;
	}
};