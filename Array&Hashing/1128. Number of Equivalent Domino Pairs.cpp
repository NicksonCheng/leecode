/*
    1. 暴力法 O(n^2)
    2. sort dominoes and find same pair O(nlogn)
    2. hashtable, 因為domino只有1~9, 所以我們可以透過 pair去組成key(小的在前面)
        然後每次找到相同的key都去加總目前hashmap裡面相同key
   pair的數量(可配對數量)
*/
class Solution {
  public:
	int numEquivDominoPairs(vector<vector<int>> &dominoes) {
		unordered_map<int, int> domino_map;

		int sum_pair = 0;
		for (auto &d : dominoes) {
			int key = 0;
			if (d[0] < d[1]) {
				key = d[0] * 10 + d[1];
			} else
				key = d[1] * 10 + d[0];
			sum_pair += domino_map[key];
			++domino_map[key];
		}
		return sum_pair;
	}
};