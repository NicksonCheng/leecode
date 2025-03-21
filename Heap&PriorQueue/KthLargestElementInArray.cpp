class Solution {
  public:
	int findKthLargest(vector<int> &nums, int k) {
		for (auto &num : nums)
			q.push(num);

		for (int i = 0; i < k - 1; ++i)
			q.pop();
		return q.top();
	}

  private:
	priority_queue<int> q;
};
