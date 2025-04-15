/*
    1. 暴力法找3個不同index組成triple, O(n^3)
    2.
*/
class Solution {
  public:
	int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
		int triple_cnt = 0;
		for (int k = 0; k < arr.size(); ++k) {

			for (int j = 0; j < k; ++j) {
				if (abs(arr[j] - arr[k]) > b) {
					continue;
				}
				for (int i = 0; i < j; ++i) {
					if (abs(arr[i] - arr[j]) <= a &&
					    abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
						++triple_cnt;
				}
			}
		}
		return triple_cnt;
	}
};