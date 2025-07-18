/*
    children 初始都0, 每次從ratings 低的開始, 跟neighbor rating比較決定數值
    map red black tree O(logn)
    greedy, time: O(nlogn), space O(n)

*/
class Solution {
  public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> children(n, 0);
		// find each rate index
		map<int, vector<int>> rate_indices;
		for (int i = 0; i < ratings.size(); ++i)
			rate_indices[ratings[i]].push_back(i);

		// start from the low rate
		int total_candies = 0;
		for (auto &m : rate_indices) {
			for (int i = 0; i < m.second.size(); ++i) {
				int idx = m.second[i];
				int l_nei = idx - 1;
				int r_nei = idx + 1;
				int candies = 1; // at least one candies

				// rating higher than left neighbor
				if (l_nei >= 0 && ratings[idx] > ratings[l_nei])
					candies = max(children[l_nei] + 1, candies);
				// rating higher that right neighbor
				if (r_nei < n && ratings[idx] > ratings[r_nei])
					candies = max(children[r_nei] + 1, candies);
				children[idx] = candies;
				total_candies += candies;
			}
		}
		return total_candies;
	}
};

/*

    sol 2. 更快方法, 雙向掃描, 大家初始candies都是 1 右邊掃一次 rating[i + 1] >
   rating[i], cadies + 1, 左邊也掃一次, 這樣就是最少的cadies數量 time O(n),
   space O(1)
*/
class Solution {
  public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> children(n, 1);
		int total_candies = 0;
		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i - 1] && children[i] <= children[i - 1]) {
				children[i] = children[i - 1] + 1;
			}
		}
		for (int i = n - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1] && children[i] <= children[i + 1]) {
				children[i] = children[i + 1] + 1;
			}
		}
		for (int &candy : children)
			total_candies += candy;
		// cout << endl;
		return total_candies;
	}
};