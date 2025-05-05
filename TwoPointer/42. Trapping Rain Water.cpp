/*
1. brutal force, 每根柱子i 都看max left/right高度去決定可以放多少水在裡面,
O(n^2)
2. hashtable儲存每個i 的prefix max, suffix max, time O(n), space O(n)

3. two pointer, 選擇比較矮的那邊算prefix_max/suffix_max

**********
*/
class Solution {
  public:
	int trap(vector<int> &height) {
		unordered_map<int, pair<int, int>> bar_map;
		int prefix_max = 0;
		int suffix_max = 0;
		int total_trap_water = 0;
		for (int l = 0; l < height.size(); ++l) {
			prefix_max = max(prefix_max, height[l]);
			bar_map[l] = {prefix_max, 0};
		}
		for (int r = height.size() - 1; r >= 0; --r) {
			suffix_max = max(suffix_max, height[r]);
			bar_map[r].second = suffix_max;
		}
		for (int i = 0; i < height.size(); ++i) {
			int trap_water =
			    min(bar_map[i].first, bar_map[i].second) - height[i];
			total_trap_water += trap_water;
		}
		return total_trap_water;
	}
};

/* Two Pointer*/
class Solution {
  public:
	int trap(vector<int> &height) {
		int l = 0;
		int r = height.size() - 1;
		int trapped_water = 0;
		int max_prefix = 0;
		int max_suffix = 0;
		while (l < r) {
			if (height[l] < height[r]) {
				if (max_prefix > height[l])
					trapped_water += max_prefix - height[l];
				else
					max_prefix = height[l];
				++l;
			} else {
				if (max_suffix > height[r])
					trapped_water += max_suffix - height[r];
				else
					max_suffix = height[r];
				--r;
			}
		}
		return trapped_water;
	}
};