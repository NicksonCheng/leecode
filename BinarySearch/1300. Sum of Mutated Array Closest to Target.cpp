/*

    1.  binary search value 0 ~ max(arr), 然後看arr[i] > value 全部改成value,
    根據distance 決定下一次search 方向
*/
class Solution {
  public:
	int findBestValue(vector<int> &arr, int target) {
		int n = arr.size();
		sort(arr.begin(), arr.end());
		int l = 0;
		int r = *max_element(arr.begin(), arr.end());
		int min_dis = INT_MAX;
		int min_value = INT_MAX;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int i = 0;
			int sum = 0;

			while (i < n) {
				if (arr[i] >= m)
					break;
				sum += arr[i++];
			}
			sum += m * (n - i);
			int dis = abs(sum - target);
			if (dis < min_dis || (dis == min_dis && m < min_value)) {
				min_dis = dis;
				min_value = m;
			}
			if (sum < target) {
				l = m + 1;
			} else if (sum > target)
				r = m - 1;
			else
				return m;
		}
		return min_value;
	}
};