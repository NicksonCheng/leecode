/*Buttom up*/
class Solution {
  public:
	int minCostClimbingStairs(vector<int> &cost) {
		vector<int> table;
		int n = cost.size();
		table.resize(n, -1);

		table[n - 1] = cost[n - 1];
		table[n - 2] = cost[n - 2];

		for (int i = n - 2; i >= 0; --i) {

			table[i] = cost[i] + min(table[i + 1], table[i + 2]);
		}
		return min(table[0], table[1]);
	}
};

/*Top Down*/
class Solution {
  public:
	vector<int> table;
	int minCostClimbingStairs(vector<int> &cost) {
		table.resize(cost.size(), -1);
		return min(recur(cost, 0), recur(cost, 1));
	}
	int recur(vector<int> &cost, int i) {
		// i is current stair idx, i>=n is on the top
		if (i >= cost.size()) {
			return 0;
		}
		if (table[i] >= 0)
			return table[i];
		// self cost + min(i+1,i+2) cost
		table[i] = cost[i] + min(recur(cost, i + 1), recur(cost, i + 2));
		return table[i];
	}
};
