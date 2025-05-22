// solution
/*

    sorting: 從start value比較小的開始排序, 依序走訪
    greedy: 從range最廣的開始拿->可以用最小的queries達成目標
    priority_queue:
        1. available: 目前還可以使用的queries, max_heap(q[1]->end長的優先), q[0]
   <= index的拿來用
        2. assign: 目前已經在用的queries, 用來查看是否match nums[index]
   size必須>=nums[index]
*/
class Solution {
  public:
	int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
		int k = 0; // 已經用過的queries不能用, k要遞增
		int count = 0;
		sort(queries.begin(), queries.end());
		priority_queue<int> available; // large end priority
		priority_queue<int, vector<int>, greater<>> assign; // low end priority

		for (int i = 0; i < nums.size(); ++i) {
			// pop outdate end from assign
			while (!assign.empty() && assign.top() < i)
				assign.pop();
			// find available queries
			while (k < queries.size() && queries[k][0] <= i) {
				available.push(queries[k][1]); // push end
				++k;
			}
			// push available into assign
			while (assign.size() < nums[i] && !available.empty() &&
			       available.top() >= i) {
				assign.push(available.top());
				available.pop();
				++count;
			}

			// still not satify nums[i]
			if (assign.size() < nums[i]) {
				return -1;
			}
		}
		return queries.size() - count;
	}
};