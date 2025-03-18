
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	int minEatingSpeed(vector<int> &piles, int h) {
		int max_k = 0;

		for (auto &p : piles)
			max_k = p > max_k ? p : max_k;

		int left = 1;
		int right = max_k;
		int res = right;
		while (left <= right) {
			/* code */
			int middle_k = (left + right) / 2;
			long long consume_h = 0;
			for (int i = 0; i < piles.size(); ++i) {
				int eat_time =
				    (long long)ceil((double)piles[i] / (double)middle_k);
				consume_h += eat_time;
			}
			if (consume_h > h)
				left = middle_k + 1;
			else {
				right = middle_k - 1;
				res = middle_k;
			}
		}
		return res;
	}
};
int main() {
	vector<int> piles = {1, 1, 1, 999999999};
	int h = 10;
	Solution sol;
	cout << sol.minEatingSpeed(piles, h) << endl;
}
