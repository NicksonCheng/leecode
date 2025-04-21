/*
    找人配對抵銷
    2個1可以抵銷成2
    3個2可以抵銷成3
    4個3可以抵銷成4
    剩下的都要變成num[i] + 1
    greedy: 能配對就儘量配對 O(n)
*/
class Solution {
  public:
	int numRabbits(vector<int> &answers) {
		int res = 0;
		unordered_map<int, int> ans_count;
		for (int &ans : answers)
			++ans_count[ans];
		for (auto &a : ans_count) {
			int ans_num = a.first;
			int count = a.second;
			// count combination group
			int num_group = count / (ans_num + 1);
			int rest_rabbit = count % (ans_num + 1); // 烙單的人自成一國
			res += num_group * (ans_num + 1);

			if (rest_rabbit > 0)
				res += ans_num + 1;
		}
		return res;
	}
};