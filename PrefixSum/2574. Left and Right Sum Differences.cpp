/*
    計算prefix的同時也計算suffix, 記得suffix要先-(題目要求)
*/
class Solution {
  public:
	vector<int> leftRightDifference(vector<int> &nums) {
		int prefix = 0;

		int suffix = 0;
		for (int &n : nums)
			suffix += n;
		vector<int> res;
		for (int &n : nums) {

			suffix -= n;
			res.push_back(abs(prefix - suffix));
			prefix += n;
		}
		return res;
	}
};