// time: 3minute
class Solution {
  public:
	int lastStoneWeight(vector<int> &stones) {
		for (auto &stone : stones)
			q.push(stone);

		while (q.size() > 1) {
			int top = q.top();
			q.pop();
			int second = q.top();
			q.pop();

			int smash_rest = top - second;
			q.push(smash_rest);
		}
		return q.top();
	}

  private:
	priority_queue<int> q;
};
