/*
    1. 先看總gas是否大於總cost, 如果大於代表一定跑得完
    2. 如果每一站的total都是正數代表都能跑完
    3. 一但遇到totoal < 0代表至今為止會失敗, 那就重新設定跑道
    4.
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int total_gas = accumulate(gas.begin(), gas.end(), 0);
		int total_cost = accumulate(cost.begin(), cost.end(), 0);
		if (total_gas < total_cost)
			return -1;
		int total = 0;
		int start_point = 0;
		for (int i = 0; i < gas.size(); ++i) {
			total += (gas[i] - cost[i]);

			if (total < 0) {
				// need to reset, this sub-route is fail;
				start_point = i + 1;
				total = 0;
			}
		}
		return start_point;
	}
};
