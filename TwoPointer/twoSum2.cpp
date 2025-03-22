class Solution {
  public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		bool find = false;
		int left = 0;
		int right = numbers.size() - 1;
		vector<int> res;
		while (!find) {
			if (target < numbers[left] + numbers[right]) {
				--right;
			} else if (target > numbers[left] + numbers[right]) {
				++left;
			} else {
				res.push_back(left + 1);
				res.push_back(right + 1);
				find = true;
			}
		}
		return res;
	}
};
