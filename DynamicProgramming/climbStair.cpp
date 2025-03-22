/* Naive Recursive*/
class Solution {
  public:
	int climbStairs(int n) {
		int count = recursive(n, 0);
		return count;
	}

  private:
	vector<int> table;
	int recursive(int n, int i) {
		if (n == i) {

			return 1;
		}
		if (n <= i)
			return 0;
		return recursive(n, i + 1) + recursive(n, i + 2);
	}
};

/* Top Down*/
class Solution {
  public:
	int climbStairs(int n) {
		table.resize(n, -1);
		int count = recursive(n, 0);
		return count;
	}

  private:
	vector<int> table;
	int recursive(int n, int i) {
		if (i >= n)
			return i == n;
		if (table[i] != -1)
			return table[i];

		table[i] = recursive(n, i + 1) + recursive(n, i + 2);

		return table[i];
	}
};

/* Buttom up */
class Solution {
  public:
	vector<int> table;
	int climbStairs(int n) {
		table.resize(n + 1, -1);
		table[n] = 1;
		table[n - 1] = 1;

		for (int i = n - 2; i >= 0; --i) {
			table[i] = table[i + 1] + table[i + 2];
		}
		return table[0];
	}
};
