
/*
    跟上一題不一樣的是meeting position 可以變化不用照原本順序

    sol.1 如果meent[i] 可以塞入其他gap, 計算拿掉後merge gap 的time, 找到max gap

    time: calculate meet/gap O(n),
    the gaps to insert meeting 如果左右找 O(n^2), 可以先sorting
   然後從最大開始找pruning, O(nlogn)


    精簡版, mutltiset + binary search
*/
#define Pair pair<int, int>
class Solution {
  public:
	int maxFreeTime(int eventTime, vector<int> &startTime,
	                vector<int> &endTime) {
		// calculate all meeting/gap time first;
		int n = startTime.size();
		int max_free_time = 0;
		vector<int> meeting(n);
		vector<int> gap(n + 1);

		for (int i = 0; i < n; ++i)
			meeting[i] = endTime[i] - startTime[i];
		gap[0] = startTime[0];
		gap[n] = eventTime - endTime[n - 1];
		for (int i = 1; i < n; ++i) {
			gap[i] = startTime[i] - endTime[i - 1];
		}

		vector<Pair> sort_gap;
		for (int i = 0; i < gap.size(); ++i) {
			sort_gap.push_back({gap[i], i});
		}
		sort(sort_gap.begin(), sort_gap.end(), greater<Pair>());
		// traverse meetings and find gaps to reschedual
		for (int i = 0; i < meeting.size(); ++i) {
			int merge_gap = gap[i] + gap[i + 1]; // minimum merge time
			for (int j = 0; j < sort_gap.size(); ++j) {
				auto [g, idx] = sort_gap[j];
				if (idx == i || idx == i + 1)
					continue;
				if (g >= meeting[i])
					merge_gap += meeting[i];
				break;
			}
			max_free_time = max(max_free_time, merge_gap);
		}
		return max_free_time;
	}
};