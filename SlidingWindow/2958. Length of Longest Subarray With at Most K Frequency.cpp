// proficient
/*
    hashtable紀錄每個num出現次數
    right expand 直到有table[num[i]] > k, 紀錄目前最大subarray length
    left expand 直到重新滿足條件
    重複以上動作

    time O(n), space O(n)
*/
class Solution {
  public:
	int maxSubarrayLength(vector<int> &nums, int k) {
		unordered_map<int, int> num_count;
		int l = 0;
		int r = 0;
		int max_subarr = 0;
		for (r = 0; r < nums.size(); ++r) {
			if (++num_count[nums[r]] > k) {
				max_subarr = max(max_subarr, r - l);
				while (nums[l] != nums[r]) {
					--num_count[nums[l++]];
				}
				// 刪掉最後nums[l] = nums[r] 讓subarray合法
				--num_count[nums[l++]];
			}
		}
		max_subarr = max(max_subarr, r - l); // 最後再比較一次
		return max_subarr;
	}
};