// solution
/*
        1. 先尋找合法區間, 在這個區間內, 進一步去尋找subarray
        two pointer + slinding window
 */
class Solution {
  public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK) {
		// 先找合法start
		long long res = 0;
		int start = 0;
		while (start < nums.size()) {

			// 先找start point
			if (nums[start] < minK || nums[start] > maxK) {
				++start;
				continue;
			}
			// 再找合法end
			int end = start;
			while (end < nums.size() && nums[end] >= minK && nums[end] <= maxK)
				++end;

			// 找合法區間[l-r], 然後往前看 l - start + 1
			// 為這個區間合法的subarray
			int last_min = -1, last_max = -1;
			for (int i = start; i < end; ++i) {
				if (nums[i] == minK)
					last_min = i; // 紀錄left的index
				if (nums[i] == maxK)
					last_max = i; // 紀錄left的index

				int left_bound = min(last_min, last_max);
				if (left_bound >= start)
					res += (left_bound - start + 1);
			}

			start = end; // next boundary start
		}
		return res;
	}
};

// 4/30 pratice again
/*
    先找合法start, 再找合法end
*/
class Solution {
  public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK) {
		int start = 0;
		long long res = 0;
		while (start < nums.size()) {

			/* find [start, end] legal range*/
			if (nums[start] < minK || nums[start] > maxK) {
				++start;
				continue;
			}
			int end = start;
			while (end < nums.size() &&
			       (nums[end] >= minK && nums[end] <= maxK))
				++end;

			// find minK, maxK position from legal range
			int min_k_pos = -1;
			int max_k_pos = -1;
			for (int i = start; i < end; ++i) {
				if (nums[i] == minK)
					min_k_pos = i;
				if (nums[i] == maxK)
					max_k_pos = i;
				if (min_k_pos != -1 && max_k_pos != -1) {
					int mini_idx = min(min_k_pos, max_k_pos);
					res += mini_idx - start + 1;
				}
			}

			// find another legal range

			start = end;
		}
		return res;
	}
};