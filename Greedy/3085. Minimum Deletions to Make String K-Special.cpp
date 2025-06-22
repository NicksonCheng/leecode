// solution
// Greedy, sorting, hashtable
/*
    一定有一個最小fraq不會被刪除
    假設fraq[i] 最小的且不被刪除fraq, 那我們就得左右看
    如果    fraq[i - 1] < fraq[i], 刪除fraq[i - 1]
            fraq[i + 1] - fraq[i] > k, 刪除fraq[i + 1] 直到 fraq[i - 1] -
   fraq[i] <= k 每個i都當作pivot 去做一次, 找到最小刪除次數
*/
class Solution {
  public:
	int minimumDeletions(string word, int k) {
		vector<int> fraq(26, 0);
		int res = 0;
		for (char &c : word) {
			++fraq[c - 'a'];
		}
		vector<int> used;
		for (int &f : fraq) {
			if (f > 0)
				used.push_back(f);
		}
		sort(used.begin(), used.end());

		// 每個i 都當作 pivot 去看左右
		int min_del = INT_MAX;
		for (int i = 0; i < used.size(); ++i) {
			// see left side
			int num_del = 0;
			for (int j = i - 1; j >= 0; --j) {
				if (used[j] < used[i])
					num_del += used[j];
			}
			for (int j = i + 1; j < used.size(); ++j) {
				int diff = used[j] - used[i];
				if (diff > k)
					num_del += diff - k;
			}

			min_del = min(min_del, num_del);
		}

		return min_del;
	}
};