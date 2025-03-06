#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
	bool hasDuplicate(vector<int> &nums) {
		unordered_map<int, bool> visit;
		for (int i = 0; i < nums.size(); ++i) {
			int value = nums[i];
			if (visit.find(value) == visit.end()) {
				visit[value] = true;
			} else
				return true;
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> nums = {3, 5, 1, 2, 4};
	cout << s.hasDuplicate(nums) << endl;
	return 0;
}