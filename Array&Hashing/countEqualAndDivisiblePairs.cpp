// proficient
// Brutal Force O(n^2)
// hashmap<int,vector<int>>, 每次都紀錄 hashmap[nums[i]].push(i);
// 每次遇到相同num進去看使否k dividable, worse cast O(n^2)
class Solution {
  public:
	int countPairs(vector<int> &nums, int k) {
		int count = 0;
		unordered_map<int, vector<int>> idx_map;

		for (int i = 0; i < nums.size(); ++i) {
			int n = nums[i];

			if (idx_map.find(n) != idx_map.end()) {
				// check k dividable
				for (int j = 0; j < idx_map[n].size(); ++j) {
					int j_idx = idx_map[n][j];
					if ((i * j_idx) % k == 0)
						++count;
				}
			}
			// push this index
			idx_map[n].push_back(i);
		}
		return count;
	}
};