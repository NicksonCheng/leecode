// solution
/*
    sliding window, we seleted k + 1 gap and merge it to maximize the window
   size

    ** 注意是n 個 time, n + 1 gaps(0 gaps也要算)
*/
class Solution {
  public:
	int maxFreeTime(int eventTime, int k, vector<int> &startTime,
	                vector<int> &endTime) {
		int n = startTime.size();
		vector<int> gaps(n + 1, 0);
		for (int i = 1; i < n; ++i) {
			gaps[i] = startTime[i] - endTime[i - 1];
		}
		gaps[0] = startTime[0];
		gaps[n] = eventTime - endTime[n - 1];

		// initialize window sum
		int window_sum = 0;

		for (int i = 0; i < k + 1; ++i) {
			window_sum += gaps[i];
		}
		int max_window = window_sum;
		// sliding window to find maximum sum of window
		int l = 0;
		int r = k + 1;
		while (r < n + 1) {
			window_sum -= gaps[l++];
			window_sum += gaps[r++];
			max_window = max(max_window, window_sum);
		}
		return max_window;
	}
};