/*
    hashtalbe (x[i],y[i]), 如果x[i] = x[j], index 換成max(y[i], y[j])

    最後用前三個最大的(map排序)
*/
#include <iostream>
#include <map>
using namespace std;
class Solution {
  public:
	int maxSumDistinctTriplet(vector<int> &x, vector<int> &y) {
		unordered_map<int, int> map_table;
		int n = x.size();
		for (int i = 0; i < n; ++i) {
			if (map_table.count(x[i]) == 0 || y[i] > map_table[x[i]])
				map_table[x[i]] = y[i];
		}
		int res = 0;
		priority_queue<int> max_heap;
		for (auto &m : map_table) {
			max_heap.push(m.second);
		}
		if (max_heap.size() < 3)
			return -1;

		for (int i = 0; i < 3; ++i) {
			res += max_heap.top();
			max_heap.pop();
		}
		return res;
	}
};
int main() {}