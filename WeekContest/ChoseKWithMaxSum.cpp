#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2,
	                             int k) {}
};
int main() {
	vector<int> nums1 = {4, 2, 1, 5, 3};
	vector<int> nums2 = {10, 20, 30, 40, 50};
	Solution sol;
	vector<long long> sum_num2 = sol.findMaxSum(nums1, nums2, 2);
	for (auto &num : sum_num2) {
		cout << num << " ";
	}
}