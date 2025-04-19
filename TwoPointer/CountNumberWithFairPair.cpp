/*
    1. brutal force O(n^2)
    2. sort + two poiner
*/
class Solution {
  public:
	long long countFairPairs(vector<int> &nums, int lower, int upper) {
		// sort nums with its index
		vector<pair<int, int>> nums_with_idx;
		for (int i = 0; i < nums.size(); ++i)
			nums_with_idx = {i, nums[i]};

		sort(nums.begin(), nums.end(),
		     [](const pair<int, int> p1, pair<int, int> p2) {
			     p1.second < p2.second
		     });
	}
};