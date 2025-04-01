// solution
/*
1. 目標在於尋找consecutive number的start point
2. 一但找到start point, 就去計算consecutive length
3. 乍看之下是O(n^2) 但每個element只會visit一次
*/
class Solution {
  public:
	int longestConsecutive(vector<int> &nums) {
		unordered_set<int> num_set(nums.begin(), nums.end());
		int max_cnt = 0;
		for (int &num : nums) {
			// this is start point, calculate consecutive number
			if (num_set.find(num - 1) == num_set.end()) {
				int len = 0;
				while (num_set.find(num) != num_set.end()) {
					++len;
					++num;
				}
				if (len > max_cnt)
					max_cnt = len;
			}
		}
		return max_cnt;
	}
};
