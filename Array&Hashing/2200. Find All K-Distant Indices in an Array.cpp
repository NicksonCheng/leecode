class Solution {
  public:
	vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
		vector<int> res;
		vector<int> visit(nums.size(), false);
		int i = 0;
		while (i < nums.size()) {
			if (nums[i] == key) {
				for (int j = max(0, i - k); j <= i + k && j < nums.size();
				     ++j) {
					if (!visit[j]) {
						res.push_back(j);
						visit[j] = true;
					}
				}
			}
			++i;
		}

		return res;
	}
};