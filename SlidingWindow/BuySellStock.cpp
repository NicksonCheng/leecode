#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	int maxProfit(vector<int> &prices) {
		int max_profit = 0;
		int curr_buy = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			int cur_profit = prices[i] - curr_buy;
			if (cur_profit > 0) {
				if (cur_profit > max_profit)
					max_profit = cur_profit;
			} else
				curr_buy = prices[i];
		}
		return max_profit;
	}
};

int main() {
	Solution sol;
	vector<int> prices = {10, 8, 7, 5, 2};
	cout << sol.maxProfit(prices) << endl;

	return 0;
}