#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	vector<vector<int>> insert(vector<vector<int>> &intervals,
	                           vector<int> &newInterval) {
		for (int i = 0; i < intervals.size(); ++i) {
			if (intervals[i][1] > newInterval[0])
				intervals[i][1] = max(intervals[i][1], newInterval[1]);
		}
	}
};

int main() {}