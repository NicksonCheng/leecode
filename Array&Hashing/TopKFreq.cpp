class Solution {
  public:
	vector<int> topKFrequent(vector<int> &nums, int k) {

		/*
		   used space to trade time complexity
		*/
		unordered_map<int, int> count;
		vector<vector<int>> fraq(
		    nums.size() +
		    1); // keeping mind that there may be same fraquenecy number
		for (auto &n : nums)
			++count[n];

		for (auto &c : count) {
			fraq[c.second].push_back(c.first);
		}
		vector<int> res;
		for (int i = fraq.size() - 1; i >= 0; --i) {
			if (fraq[i].empty())
				continue;
			for (auto &f : fraq[i])
				res.push_back(f);
			if (res.size() >= k)
				break;
		}
		return res;
	}
};
